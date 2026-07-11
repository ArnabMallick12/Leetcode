class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    public:
    
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] =1;
        }
        
    }
    
    int find(int node){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
        
    }
    void unite(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
        
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mp;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else{
                    ds.unite(i,mp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> mergemail(n);
        for(auto it : mp){
            string email = it.first;
            int node = ds.find(it.second);
            mergemail[node].push_back(email);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergemail[i].size()==0) continue;
            vector<string> temp;
            sort(mergemail[i].begin(), mergemail[i].end());
            temp.push_back(accounts[i][0]);
            for(auto e : mergemail[i]){
                temp.push_back(e);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};