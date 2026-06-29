class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int points[102] = {0};
        int ans =0;
        for(auto i : nums){
            points[i[0]] ++;
            points[i[1]+1] --;
        }
        for(int i=1;i<102;i++){
            points[i] += points[i-1];
            if(points[i]!=0) ans++;
        }
        return ans;
    }
};