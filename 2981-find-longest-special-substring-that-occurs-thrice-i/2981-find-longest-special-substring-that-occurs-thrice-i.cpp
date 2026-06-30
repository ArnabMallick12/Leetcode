class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                bool special = true;
                for (int k = i + 1; k <= j; k++) {
                    if (s[k] != s[i]) {
                        special = false;
                        break;
                    }
                }
                if (special)
                    mp[s.substr(i, j - i + 1)]++;
                if (mp[s.substr(i, j - i + 1)] >= 3) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};