class Solution {
public:
    bool issafe(int r,int c,char num,vector<vector<char>>& board ){
        //row
        for(int i=0;i<9;i++){
            if(board[i][c]==num) return false;
        }
        //col
        for(int i=0;i<9;i++){
            if(board[r][i]==num) return false;
        }
        //matrix 3x3
        int sr = 3*(r/3);
        int sc = 3*(c/3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[sr+i][sc+j]==num){
                    return false;
                }
            }
        }
        return true;

    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(issafe(i,j,c,board)){
                            board[i][j] = c;
                            if(solve(board)) return true;
                            board[i][j] ='.';
                            
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};