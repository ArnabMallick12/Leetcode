class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);

            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }

        if(ans.size()!=n) return {};
        
        return ans;
    }
};