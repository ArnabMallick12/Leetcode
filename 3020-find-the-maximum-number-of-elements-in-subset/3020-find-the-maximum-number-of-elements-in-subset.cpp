class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 1;
        unordered_map<long long,int> freq;
        for(int  i : nums){
            freq[i]++;
        }
        for(int i =0 ;i<nums.size();i++){
            long long num = nums[i];
            if(num ==1){
                
                if(freq[num]%2==1) ans = max(ans,freq[num]);
                else ans = max(ans,freq[num]-1);
                continue;

            }
            int cnt = 1;
            while(freq[num]>=2 && freq.find(num*num)!=freq.end()){
                cnt+=2;
                num = num*num;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};