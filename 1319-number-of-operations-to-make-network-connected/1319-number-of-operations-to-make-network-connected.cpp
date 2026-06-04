class Solution {
public:
    void dfs(int node, vector<int>& vis,vector<vector<int>>& adj ){
        vis[node] = 1;
        for(auto u : adj[node]){
            if(vis[u]==-1){
                dfs(u,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()) return -1;
        vector<vector<int>> adj(n);
        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int cnt =0;
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt-1;
    }
};