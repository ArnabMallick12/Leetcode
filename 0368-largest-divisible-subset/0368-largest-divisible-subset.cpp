class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int lastind = -1 , maxi =0;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1), hash(n);
        for(int i =0 ;i<n;i++){
            hash[i]=i;
            for(int j = i-1;j>=0;j--){
                if( nums[i]%nums[j]==0){
                    if(1+dp[j]>dp[i]){
                        dp[i] = 1+dp[j];
                        hash[i] = j;
                    }
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastind = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastind]);
        while(lastind!=hash[lastind]){
            lastind = hash[lastind];
            temp.push_back(nums[lastind]);
        }
        // cout<<maxi<<" ";
        return temp;
    }
};