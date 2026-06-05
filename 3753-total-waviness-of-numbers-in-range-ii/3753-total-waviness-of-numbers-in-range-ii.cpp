class Solution {
public:
    struct Node {
        long long cnt;
        long long waviness;
        Node(long long c = 0, long long w = 0) : cnt(c), waviness(w) {}
    };

    string s;
    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node dfs(int pos, int tight, int started, int prev2, int prev1) {
        if (pos == s.size()) {
            return Node(1, 0);
        }

        if (vis[pos][tight][started][prev2][prev1])
            return dp[pos][tight][started][prev2][prev1];

        vis[pos][tight][started][prev2][prev1] = true;

        Node res;

        int limit = tight ? (s[pos] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node child = dfs(pos + 1, ntight, 0, 10, 10);
                res.cnt += child.cnt;
                res.waviness += child.waviness;
            } else {
                long long add = 0;

                if (started && prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                int nprev2, nprev1;

                if (!started) {
                    nprev2 = 10; // only one digit chosen so far
                    nprev1 = d;
                } else if (prev2 == 10) {
                    nprev2 = prev1;
                    nprev1 = d;
                } else {
                    nprev2 = prev1;
                    nprev1 = d;
                }

                Node child =
                    dfs(pos + 1, ntight, 1, nprev2, nprev1);

                res.cnt += child.cnt;
                res.waviness += child.waviness + add * child.cnt;
            }
        }

        return dp[pos][tight][started][prev2][prev1] = res;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, 10, 10).waviness;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};