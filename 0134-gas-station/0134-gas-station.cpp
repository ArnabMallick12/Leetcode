class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tt=0,ct=0,ans=0;
        for (int i = 0; i < n; i++) {
            int diff = gas[i]-cost[i];
            tt+= diff;
            ct+=diff;
            if(ct<0){
                ans=i+1;
                ct=0;
            }
        }
        if(tt>=0){
            return ans;
        }
        else{
            return -1;
        }
    }
};
