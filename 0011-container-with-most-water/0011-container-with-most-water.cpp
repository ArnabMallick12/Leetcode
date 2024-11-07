class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=0;
        while(j>i){
            int mh = min(height[i],height[j]);
            int temp = (j-i)*mh;
            if(ans<temp){
                ans=temp;
            }
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};