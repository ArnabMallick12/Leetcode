class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int ans = 1;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(auto i:s){
            if(s.find(i -1) == s.end()){
                int cnt = 1;
                int x=i;
                while(s.find(x+1)!=s.end()){
                    x ++;
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};