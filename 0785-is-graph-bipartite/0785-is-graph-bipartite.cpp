class Solution {
public:
    bool fn(int node, int color, vector<int>& colors,vector<int>& vis,vector<vector<int>>& graph){
        vis[node] = 1;
        colors[node] = color;
        cout<<node<<" color "<<color<<endl;
        for(auto u : graph[node]){
            if(vis[u]==-1){
                if (!fn(u,!color,colors,vis,graph)) return false;
            }
            else{
                if(colors[u]==color) {
                    cout<<node<<" "<<u<<"->false"<<endl;
                    return false;
                }
                 cout<<node<<" "<<u<<"->true"<<endl;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        vector<int> colors(n,-1);
        int col=0;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                    cout<<"main called node: "<<i<<endl;
                if(fn(i,col,colors,vis,graph)==false) {
                    return false;
                }
                // col=!col;
            }
        }
        return true;
    }
};