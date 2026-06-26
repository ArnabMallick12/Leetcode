class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int totalOnes = 0;
        for (char c : s){
            if (c == '1') totalOnes++;
        }

        int ans = 0;
        // case 1 : all 1 or 0
        ans = min(totalOnes, n-totalOnes); // flip all 1->0 or 0->1 whichever is min
        //case 2 : ...000010000... exactly one 1
        ans = min(ans, totalOnes-1); // only keep one 1 and flip rest of 1's
        //case 3: 10000....00001  1 at both the ends and 0's in between
        if(n>1){
            int cnt =0;
            if(s[0]=='0') cnt++;
            if(s[n-1]=='0') cnt++;
             
            for(int i=1;i<n-1;i++){
                if(s[i]=='1') cnt++;
            }
            ans = min(cnt,ans);
            // if()    // 1001100 , 001100 , 100111001

        }
        if(ans<0) return 0;
        return ans;
    }
};