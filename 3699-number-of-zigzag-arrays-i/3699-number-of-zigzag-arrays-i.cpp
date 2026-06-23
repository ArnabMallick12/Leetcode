class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 1, 0), down(m + 1, 0);

        // Length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        if (n == 2) {
            long long ans = 0;
            for (int v = 1; v <= m; v++) {
                ans = (ans + up[v] + down[v]) % MOD;
            }
            return (int)ans;
        }

        vector<int> nup(m + 1), ndown(m + 1);
        vector<int> pref(m + 1);

        for (int len = 3; len <= n; len++) {

            // Build newUp from prefix sums of down
            pref[0] = 0;
            for (int i = 1; i <= m; i++) {
                pref[i] = pref[i - 1] + down[i];
                if (pref[i] >= MOD) pref[i] -= MOD;
            }

            for (int v = 1; v <= m; v++) {
                nup[v] = pref[v - 1];
            }

            // Build newDown from suffix sums of up
            pref[0] = 0;
            for (int i = 1; i <= m; i++) {
                pref[i] = pref[i - 1] + up[i];
                if (pref[i] >= MOD) pref[i] -= MOD;
            }

            for (int v = 1; v <= m; v++) {
                ndown[v] = pref[m] - pref[v];
                if (ndown[v] < 0) ndown[v] += MOD;
            }

            up.swap(nup);
            down.swap(ndown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) {
            ans += up[v];
            ans += down[v];
            ans %= MOD;
        }

        return (int)ans;
    }
};