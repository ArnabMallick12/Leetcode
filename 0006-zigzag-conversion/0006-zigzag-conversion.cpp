class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<vector<char>> matrix(numRows);
        int row = 0;
        int col =1;
        for(auto c :s){
            matrix[row].push_back(c);
            if(row ==0){
                col=1;
            }
            if(row == numRows -1) {col = -1;}
            row+=col;
        }
        string ans;
        for(auto i : matrix){
            for(auto j :i ){
                ans+=j;
            }
        }
        return ans;
    }
};