class Solution {
public:
    bool dfs(int i,int j, int sz, string word,vector<vector<char>>& board,vector<vector<int>>& vis ){
        if(sz == word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[sz] || vis[i][j]==1 ) return false;
        vis[i][j] =1;
        bool fn = dfs(i+1,j,sz+1,word,board,vis) || dfs(i-1,j,sz+1,word,board,vis) || dfs(i,j+1,sz+1,word,board,vis) || dfs(i,j-1,sz+1,word,board,vis);
        vis[i][j] =0;
        return fn;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m =board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0,word,board,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};