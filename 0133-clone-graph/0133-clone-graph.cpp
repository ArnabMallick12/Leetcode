/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node *clone = new Node;
        clone->val = node->val;
        unordered_map<Node*,Node*> mp;
        mp[node] = clone;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            for(auto i : n->neighbors){
                if(mp.find(i) == mp.end()){
                    Node *c = new Node(i->val);
                    mp[i] = c;
                    q.push(i);
                }
                mp[n]->neighbors.push_back(mp[i]);
            }
        }
        return mp[node];
    }
};