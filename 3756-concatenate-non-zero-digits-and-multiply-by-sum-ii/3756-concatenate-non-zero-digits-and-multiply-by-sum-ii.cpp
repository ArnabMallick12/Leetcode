class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefNum(n + 1, 0);   // prefix number using only non-zero digits
        vector<long long> prefSum(n + 1, 0);   // prefix digit sum
        vector<int> cnt(n + 1, 0);             // prefix count of non-zero digits

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            prefSum[i + 1] = prefSum[i] + d;
            cnt[i + 1] = cnt[i];

            if (d == 0) {
                prefNum[i + 1] = prefNum[i];
            } else {
                cnt[i + 1]++;
                prefNum[i + 1] = (prefNum[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            int nonZero = cnt[r + 1] - cnt[l];

            long long num =
                (prefNum[r + 1] -
                 prefNum[l] * pow10[nonZero] % MOD +
                 MOD) % MOD;

            ans.push_back((num * (sum % MOD)) % MOD);
        }

        return ans;
    }
};