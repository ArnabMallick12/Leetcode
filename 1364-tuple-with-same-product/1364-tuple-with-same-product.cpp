class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i)
      for (int j = 0; j < i; ++j)
        ans += mp[nums[i] * nums[j]]++ * 8;

    return ans;
  }
};