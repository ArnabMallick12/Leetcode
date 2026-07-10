class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        // (value, original index)
        vector<pair<int,int>> arr;
        arr.reserve(n);
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        // pos[node] = position in sorted order
        // comp[node] = connected component id
        vector<int> pos(n), comp(n);

        int cid = 0;
        pos[arr[0].second] = 0;
        comp[arr[0].second] = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first > maxDiff)
                cid++;

            pos[arr[i].second] = i;
            comp[arr[i].second] = cid;
        }

        // next[i] = farthest position reachable in one edge
        vector<int> nxt(n);
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n &&
                   arr[r + 1].first - arr[l].first <= maxDiff)
                r++;
            nxt[l] = r;
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));

        up[0] = nxt;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            int a = pos[u];
            int b = pos[v];

            if (a > b) swap(a, b);

            int cur = a;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            if (cur < b) steps++;

            ans.push_back(steps);
        }

        return ans;
    }
};