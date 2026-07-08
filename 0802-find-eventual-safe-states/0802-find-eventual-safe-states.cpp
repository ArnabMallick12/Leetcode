class Solution {
public:
    bool dfs(int node , vector<int> &vis, vector<int> &path , vector<int> &safe ,vector<vector<int>>& adj ){
        vis[node] =1;
        path[node] =1;
        for(auto v : adj[node]){
            if(!vis[v]){
                if(dfs(v,vis,path,safe,adj)) return true;
            }
            else {
                if(path[v]) return true;
            }
        }
        path[node] = 0;
        safe[node] =1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0) , path(n,0) , safe(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,path,safe,graph);
            }
        }
        vector<int> safeNodes;
        for(int i=0;i<n;i++){
            if(safe[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};