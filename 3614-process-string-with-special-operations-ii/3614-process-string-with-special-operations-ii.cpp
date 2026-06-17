class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        const long long LIM = 1e15 + 5;

        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                len[i + 1] = min(LIM, len[i] + 1);
            }
            else if (c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (c == '#') {
                len[i + 1] = min(LIM, len[i] * 2);
            }
            else { // %
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long prev = len[i];

            if ('a' <= c && c <= 'z') {
                if (k == prev) return c;
            }
            else if (c == '#') {
                if (k >= prev) k -= prev;
            }
            else if (c == '%') {
                if (prev > 0)
                    k = prev - 1 - k;
            }
            // '*' does nothing in reverse
        }

        return '.';
    }
};