class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int collectedBills[3] = {0};
        for (int i = 0; i < bills.size(); i++) {
            if(bills[i]==5) collectedBills[0]++;
            else if (bills[i]==10){
                if(collectedBills[0]==0) return false;
                else{
                   collectedBills[0]--;
                   collectedBills[1]++; 
                }
            }
            else{
                if(collectedBills[0]>0 && collectedBills[1]>0){
                    collectedBills[0]--;
                    collectedBills[1]--;
                }
                else if(collectedBills[0]>=3){
                    collectedBills[0]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};