class Solution {
public:
    int solve(int i, int sum, vector<int>& nums,
              vector<vector<int>>& dp, int offset, int target) {

        if (i == nums.size()) {
            return (sum == target);
        }

        if (dp[i][sum + offset] != -1)
            return dp[i][sum + offset];

        int add = solve(i + 1, sum + nums[i], nums,
                        dp, offset, target);

        int sub = solve(i + 1, sum - nums[i], nums,
                        dp, offset, target);

        return dp[i][sum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total)
            return 0;

        int offset = total;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(2 * total + 1, -1)
        );

        return solve(0, 0, nums, dp, offset, target);
    }
};