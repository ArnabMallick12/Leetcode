class DisjointSet{
    vector<int> rank;
    vector<int> size;
    public:
    
    vector<int> parent;
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
    void unionBySize(int u,int v){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for(auto c : connections){
            if(ds.find(c[0])==ds.find(c[1])) extraEdges++;
            else ds.unionBySize(c[0],c[1]);
        }
        unordered_set<int> components;
        for(int i=0;i<n;i++){
            components.insert(ds.find(i));
        }
        if(components.size()-1 <= extraEdges) return components.size()-1;
        return -1;
    }
};