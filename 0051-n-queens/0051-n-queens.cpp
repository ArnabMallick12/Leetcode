class Solution {
public:
    void fn(int n,int col,vector<vector<string>>& ans, vector<string>& br,vector<int>& lc,
        vector<int>& ld,
        vector<int>& ud ){
            if(col==n){
                ans.push_back(br);
                return;
            }
            for(int r=0;r<n;r++){
                if(lc[r]==0 && ld[r+col]==0 && ud[n-1+col-r]==0){
                    br[r][col] = 'Q';
                    lc[r]=1;
                    ld[r+col]=1;
                    ud[n-1+col-r]=1;
                    fn(n,col+1,ans,br,lc,ld,ud);
                    br[r][col] = '.';
                    lc[r]=0;
                    ld[r+col]=0;
                    ud[n-1+col-r]=0;
                }
            }
        }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> br(n,string(n,'.'));
        vector<int> lc(n,0);
        vector<int> ld(2*n-1,0);
        vector<int> ud(2*n-1,0);
        fn(n,0,ans,br,lc,ld,ud);
        return ans;
    }
};