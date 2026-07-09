class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.assign(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int x, int y) {
            x = find(x);
            y = find(y);

            if (x == y) return;

            if (rank[x] < rank[y])
                parent[x] = y;
            else if (rank[x] > rank[y])
                parent[y] = x;
            else {
                parent[y] = x;
                rank[x]++;
            }
        }
    };

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                dsu.unite(i, i - 1);
        }

        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(dsu.find(q[0]) == dsu.find(q[1]));
        }

        return ans;
    }
};