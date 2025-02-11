class Solution {
 public:
  string removeOccurrences(string s, string part) {
    const int n = s.length();
    const int k = part.length();

    string ans(n, ' ');
    int j = 0; 

    for (int i = 0; i < n; ++i) {
      ans[j++] = s[i];
      if (j >= k && ans.substr(j - k, k) == part)
        j -= k;
    }
    return ans.substr(0, j);
  }
};