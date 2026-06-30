class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        vector<vector<int>> freq(26, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            int len = 1;
            freq[s[i] - 'a'][1]++;

            for (int j = i; j + 1 < n; j++) {
                if (s[j] == s[j + 1]) {
                    len++;
                    freq[s[i] - 'a'][len]++;
                } else {
                    break;
                }
            }
        }

        for (int len = n; len >= 1; len--) {
            for (int c = 0; c < 26; c++) {
                if (freq[c][len] >= 3)
                    return len;
            }
        }

        return -1;
    }
};