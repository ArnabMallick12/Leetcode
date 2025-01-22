class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        vector<pair<int,int>> d = {{0,1},{-1,0},{0,-1},{1,0}};
        queue<pair<int,int>> q;
        for(int i =0; i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j] == 1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [a,b] = q.front();
            q.pop();
            for(auto [dx,dy] : d){
                int i = a+dx;
                int j = b+dy;
            
            if((i<m && j<n && i >=0 && j>=0 ) && ans[i][j] == -1){
                ans[i][j]=ans[a][b] +1;
                q.push({i,j}) ;
                }
            }
        }
        return ans;
    }
};