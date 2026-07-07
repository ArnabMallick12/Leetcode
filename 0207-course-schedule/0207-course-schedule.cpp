class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &path){
        vis[node] =1 ;
        path[node] =1;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return true;
            }
            else{
                if(path[i]) return true;
            }
        }
        path[node] =0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        vector<int> vis(numCourses,0) , path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(dfs(i,adj,vis,path)) return false;
        }
        return true;
    }
};