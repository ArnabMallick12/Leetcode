class Solution {
public:
     long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int v=1 , h=1;
        long long ans =0 ;
        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
        sort(verticalCut.begin(),verticalCut.end(),greater<int>());
        int i=0,j=0;
        while(i<horizontalCut.size() && j<verticalCut.size()){
            if(horizontalCut[i]>=verticalCut[j]){
                ans += horizontalCut[i]*v;
                h++;
                i++;
            }
            else{
                ans+= verticalCut[j]*h;
                v++;
                j++;
            }
        }
        while(i<horizontalCut.size()){
            ans += horizontalCut[i]*v;
            h++;
            i++; 
        }
        while(j<verticalCut.size()){
            ans+= verticalCut[j]*h;
            v++;
            j++;
        }
        return ans;
    }
};