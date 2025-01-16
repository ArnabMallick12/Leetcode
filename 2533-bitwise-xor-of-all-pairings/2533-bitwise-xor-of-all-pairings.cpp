class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int xor2 = 0;
        int xor1 = 0;
        int n = nums1.size();
        int m = nums2.size();

        for (int i=0;i<n;i++){
            xor1 ^= nums1[i];
        } 
        for (int j=0;j<m;j++){
            xor2 ^= nums2[j];
        } 

        if (m % 2 == 1) {
            ans ^= xor1;
            } 
        if (n % 2 == 1) {
            ans ^= xor2;
        }

        return ans;
    }
};
