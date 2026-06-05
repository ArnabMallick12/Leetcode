class Solution {
public:
    int fn(int l,int r,vector<int> &nums){
        int prev2=0,prev=0;
        for(int i=l;i<=r;i++){
            int inc = nums[i]+prev2;
            int ex = prev;
            int curr = max(inc,ex);
            prev2 = prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(fn(0,n-2,nums),fn(1,n-1,nums));
    }
};