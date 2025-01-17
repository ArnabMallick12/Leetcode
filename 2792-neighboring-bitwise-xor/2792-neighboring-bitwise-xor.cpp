class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int txor = 0;
        for(int i=0;i<derived.size();i++){
            txor^=derived[i];
        }
        if(txor ==0) return true;
        else return false;
    }
};