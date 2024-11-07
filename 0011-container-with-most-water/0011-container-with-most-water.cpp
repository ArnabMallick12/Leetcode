class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=0;
        while(j>i){
            int temp = (j-i)*min(height[i],height[j]);
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