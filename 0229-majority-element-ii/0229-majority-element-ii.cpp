class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int el1 = INT_MIN, el2 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && el2!=nums[i]){
                cnt1++;
                el1 = nums[i];
            }
            else if(cnt2==0 && el1!=nums[i]){
                cnt2++;
                el2 = nums[i];
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i:nums){
            if(i==el1) cnt1++;
            else if(i==el2) cnt2++;
        }
        int min = nums.size()/3+1;
        vector<int> ans;
        if(cnt1>=min) ans.push_back(el1);
        if(cnt2>=min && el1!=el2) ans.push_back(el2);

        return ans;
    }
};