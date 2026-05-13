class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact=1;
        for(int i=1;i<=n;i++){
            fact*=i;
            nums.push_back(i);
        }
        k--;
        string ans="";
        int size = fact/n;
        while(true){
            int val = nums[k/size];
            ans.push_back(val + '0');
            nums.erase(nums.begin() + k/size);
            if(nums.size()==0) break;
            k = k%size;
            size/=nums.size();

        }
        return ans;
    }
};