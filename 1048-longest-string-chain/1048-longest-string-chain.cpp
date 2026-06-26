class Solution {
public:
    bool fn(string s, string t) { // s -> t
        if (t.size() != s.size() + 1)
            return false;

        int i = 0, j = 0;
        while (j < t.size()) {
            if (i < s.size() && s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (fn(words[j], words[i]) == 1) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};