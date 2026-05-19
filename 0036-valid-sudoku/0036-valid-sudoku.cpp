class Solution {
public:
    bool issafe(int val , int r , int c , vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(i!=r && board[i][c]==val){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(i!=c && board[r][i]==val){
                return false;
            }
        }
        int sr = 3*(r/3);
        int sc = 3*(c/3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(((sr+i)!=r && (sc+j)!=c) && board[sr+i][sc+j]==val){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && !issafe(board[i][j],i,j,board)) return false;
            }
        }
        return true;
    }
};