class Solution {
public:
    int fn(vector<int>& nums1, vector<int>& nums2){
        int ans =0 ;
        for(int i=0;i<nums1.size();i++){
            long long x = nums1[i];
            long long target = x*x;
            unordered_map<long long,int> freq;
            for(int j=0;j<nums2.size();j++){
                if(target%nums2[j]==0){
                    long long need =target/nums2[j];
                    if(freq.count(need)){
                        ans+=freq[need];
                    }
                }
                freq[nums2[j]]++;
            }
        }
        return ans;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return fn(nums1,nums2)  + fn(nums2,nums1);
    }
};