class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum =0 ;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        if(n==k) return sum;
        int ans = sum;
        for(int i = 0;i<k;i++){
            sum-=cardPoints[k-i-1];
            sum+= cardPoints[n-1-i];
            ans = max(ans,sum);
        }
        return ans;
    }
};