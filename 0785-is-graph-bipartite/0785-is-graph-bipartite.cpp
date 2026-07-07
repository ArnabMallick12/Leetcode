class Solution {
public:
    bool dfs(int node, int color, vector<int> &colors ,  vector<vector<int>>& adj){
        // vis[node] =1;
        colors[node] = color;
        for(auto i : adj[node]){
            if(colors[i]==-1){
                if(!dfs(i,!color,colors,adj)) return false;
            }
            else{
                if(colors[i] == color) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // vector<int> vis(n,0);
        vector<int> colors(n,-1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(!dfs(i,0,colors,graph)) return false;
            }
        }
        return true;
    }
};