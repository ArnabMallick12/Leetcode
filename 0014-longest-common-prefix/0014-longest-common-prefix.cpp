class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0){
            return ""; 
        }
        if (strs.size() == 1){
            return strs[0]; 
        }
        int index=1000;
        
        for (int i=1;i<strs.size();i++){
            int count=0;
            for(int j=0;j<min(strs[i-1].length(),strs[i].length());j++){
                if(strs[i-1][j]==strs[i][j]){
                    count++;
                }
                else{
                    break;
                }
            }

            if(count<index){
                index=count;
            }
        }
        return strs[0].substr(0,index);
    }
};