struct Node{
        int key;
        int val;
        int cnt;
        Node* next;
        Node* prev;
        Node(int k, int v){
            key = k;
            val =v;
            cnt =1;
        }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next= tail;
        tail->prev = head;
        size =0;
    }
    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev  = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* node){
        Node* delnext = node->next;
        Node* delprev = node->prev;
        delprev->next = delnext;
        delnext->prev  =delprev;
        size--;
    }
};
class LFUCache {
public:
    int cap;
    unordered_map<int , Node*> m;
    unordered_map<int,List*> freq;
    int minfreq;
    int csize;
    LFUCache(int capacity) {
        cap = capacity;
        minfreq=0;
        csize=0;
    }
    void updatefreq(Node* node){
        m.erase(node->key);
        freq[node->cnt]->removeNode(node);
        if(node->cnt == minfreq && freq[node->cnt]->size==0){
            minfreq++;
        }
       List* newfreqlist = new List();
        if(freq.find(node->cnt+1)!=freq.end()){
            newfreqlist = freq[node->cnt+1];
        }
        node->cnt +=1;
        newfreqlist->addNode(node);
        m[node->key] = node;
        freq[node->cnt]  =newfreqlist;
    }    
    int get(int k) {
        if(m.find(k)!=m.end()){
            Node* node = m[k];
            int ans = node->val;
            updatefreq(node);
            return ans;
        }
        return -1;
    }
    
    void put(int k, int v) {
        if(cap==0) return;
        if(m.find(k)!=m.end()){
            Node* node = m[k];
            node->val = v;
            updatefreq(node);
        }
        else{
            if(csize == cap){
                List* list = freq[minfreq];
                m.erase(list->tail->prev->key);
                freq[minfreq]->removeNode(list->tail->prev);
                csize--;
            }
            csize++;
            minfreq=1;
            List* listf = new List();
            if(freq.find(minfreq)!=freq.end()){
                listf = freq[minfreq];
            }
            Node* node  = new Node(k,v);
            listf->addNode(node);
            m[k] = node;
            freq[minfreq] = listf;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */