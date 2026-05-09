class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int l = min(n,m)/2;
        for(int i=0;i<l;i++){
            vector<int> temp;
            int top =i;
            int left = i;
            int bottom = m-i-1;
            int right = n-i-1;
            for(int j=left;j<=right;j++){
                temp.push_back(grid[top][j]);
            }
            for(int j=top+1;j<=bottom-1;j++){
                temp.push_back(grid[j][right]);
            }
            for(int j=right;j>=left;j--){
                temp.push_back(grid[bottom][j]);
            }
            for(int j=bottom-1;j>=top+1;j--){
                temp.push_back(grid[j][left]);
            }

            int len = temp.size();
            vector<int> r(len);
            int rot = k%len;
            for(int j=0;j<len;j++){
                r[j] = temp[(j+rot)%len];
            }
            int x=0;
            for(int j=left;j<=right;j++){
                grid[top][j] = r[x++];
            }
            for(int j=top+1;j<=bottom-1;j++){
                grid[j][right]= r[x++];
            }
            for(int j=right;j>=left;j--){
                grid[bottom][j]= r[x++];
            }
            for(int j=bottom-1;j>=top+1;j--){
                grid[j][left]= r[x++];
            }

        }
        return grid;
    }
};