class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cntin =1;
        int cntdec =1;
        int tcntin =1;
        int tcntdec =1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                tcntin++;
                cntdec = max(tcntdec,cntdec);
                tcntdec=1;
            }
            else if(nums[i]<nums[i-1]){
                tcntdec++;
                cntin = max(tcntin,cntin);
                tcntin=1;
            }
            else{
                cntdec = max(tcntdec,cntdec);
                tcntdec=1;
                cntin = max(tcntin,cntin);
                tcntin=1;
            }
        }
        cntdec = max(tcntdec,cntdec);
        cntin = max(tcntin,cntin);
        return max(cntin,cntdec);
    }
};