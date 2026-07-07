class Solution {
public:
    bool bfs(int node , vector<vector<int>>& adj , vector<int> &vis){
        int n =0;
        int m = 0;
        vis[node] =1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            n++;
            for(auto i :adj[curr]){
                m++;
                if(!vis[i]){
                    vis[i] =1;
                    q.push(i);
                }
            }
        }
        m = m/2;
        return m == (n*(n-1))/2;

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i] && bfs(i,adj,vis)){
                ans++;
            }
        }
        return ans;
    }
};