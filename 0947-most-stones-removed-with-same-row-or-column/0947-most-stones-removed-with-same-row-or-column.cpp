class Solution {
public:

    unordered_map<int,int> parent;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa != pb){
            parent[pa] = pb;
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        for(auto &s : stones){
            int r = s[0];
            int c = s[1] + 10001;

            if(!parent.count(r)) parent[r] = r;
            if(!parent.count(c)) parent[c] = c;

            unite(r,c);
        }

        unordered_set<int> comp;

        for(auto &s : stones){
            comp.insert(find(s[0]));
        }

        return stones.size() - comp.size();
    }
};