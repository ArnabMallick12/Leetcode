class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int i=0,j=0;
        int n = nums1.size(),m = nums2.size();
        while(i<n && j<m){
            if(nums1[i]<nums2[j]) temp.push_back(nums1[i++]);
            else temp.push_back(nums2[j++]);
        }
        while(i<n) temp.push_back(nums1[i++]);
        while(j<m) temp.push_back(nums2[j++]);

        if((n+m)%2==0){
            return ((double)(temp[(n+m)/2-1]  + temp[(n+m)/2]))/2.0;
        }
        else return (double)(temp[(n+m)/2]);
    }
};