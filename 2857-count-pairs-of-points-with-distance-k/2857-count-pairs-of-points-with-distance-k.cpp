class Solution {
public:
    int countPairs(vector<vector<int>>& c, int k) {
        int n = c.size();
        int ans = 0;
        unordered_map<long long, int> freq;
        for(int i=0;i<n;i++){
            int x1 = c[i][0];
            int y1 = c[i][1];
            for(int j =0;j<=k;j++){
                int x2 = j^x1;
                int y2 = (k-j)^y1;
                long long key = ((long long)x2 <<32) | (unsigned int)y2;
                ans += freq[key];
            }
            long long key = ((long long)x1 <<32) | (unsigned int)y1;
            freq[key]++;
        }
        return ans;
    }
};