class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int  n = boxGrid[0].size();
        vector<vector<char>> ans(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = boxGrid[j][i];
            }
            reverse(ans[i].begin(),ans[i].end());
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int j=0;j<m;j++){
            for(int i=n-2;i>=0;i--){
                if(ans[i][j]=='#'){
                    int k=i;
                    while(k+1<n&&ans[k+1][j]=='.'){
                        swap(ans[k][j],ans[k+1][j]);
                        k++;
                    }
                }
            }
        }

        return ans;
    }
};