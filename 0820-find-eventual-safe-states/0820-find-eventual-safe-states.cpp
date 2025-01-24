class Solution {
public:
    bool dfscheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis, vector<int> &check){
        vis[node] =1;
        pathvis[node]=1;
        check[node]=0;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfscheck(i , adj , vis,pathvis,check)){
                    return true;
                }
            }
                else if(pathvis[i]){
                    return true;
                }
            
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,0);
        vector<int> pathvis(v,0);
        vector<int> ans;
        vector<int> check(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfscheck(i,graph,vis,pathvis,check);
            }
        }
        for(int i=0;i<v;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};