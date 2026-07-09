class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : flights){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
        }

        queue<pair<int,pair<int,int>>> q;
        // {stops, {node, cost}}

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        q.push({0, {src, 0}});

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto &i : adj[node]){

                int adjNode = i.first;
                int wt = i.second;

                if(cost + wt < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + wt;
                    q.push({stops + 1, {adjNode, cost + wt}});
                }
            }
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};