class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long MOD = 1e9+7;

        vector<vector<pair<int,int>>> adj(n);

        for(auto &r : roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);

        priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            long long d = it.first;
            int node = it.second;

            for(auto &x : adj[node]){

                int adjNode = x.first;
                long long wt = x.second;

                if(d + wt < dist[adjNode]){

                    dist[adjNode] = d + wt;
                    ways[adjNode] = ways[node];

                    pq.push({dist[adjNode], adjNode});
                }

                else if(d + wt == dist[adjNode]){

                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};