class Solution {
public:
    bool dfs(int node, int color, vector<int> &colors , vector<int> &vis, vector<vector<int>>& adj){
        vis[node] =1;
        colors[node] = color;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(!dfs(i,!color,colors,vis,adj)) return false;
            }
            else{
                if(colors[i] == color) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> colors(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(i,0,colors,vis,graph)) return false;
            }
        }
        return true;
    }
};