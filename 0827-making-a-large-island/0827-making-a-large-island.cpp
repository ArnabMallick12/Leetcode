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
    int getSize(int node){
        return size[find(node)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                for(int x=0;x<4;x++){
                    int nr = i+dr[x];
                    int nc = j+ dc[x];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int node =  i*n +j;
                        int adjnode = nr*n + nc;
                        ds.unite(node,adjnode);
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                unordered_set<int> st;
                int size=1;
                for(int x=0;x<4;x++){
                    int nr = i+dr[x];
                    int nc = j+ dc[x];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int adjnode = nr*n + nc;
                        st.insert(ds.find(adjnode));
                    }
                }
                for(auto it : st){
                    size+=ds.getSize(it);
                }
                ans = max(ans,size);
            }
            
        }
        for (int i = 0; i < n * n; i++) {
            ans = max(ans, ds.getSize(ds.find(i)));
        }
        return ans;
    }
};