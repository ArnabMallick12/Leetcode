class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {-1, 0}));
        // {maxScore, ways}

        dp[0][0] = {0, 1}; // start from E

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'X') continue;
                if(i == 0 && j == 0) continue;

                int maxScore = -1;
                int ways = 0;

                vector<pair<int,int>> prev;

                if(i > 0) prev.push_back(dp[i-1][j]);
                if(j > 0) prev.push_back(dp[i][j-1]);
                if(i > 0 && j > 0) prev.push_back(dp[i-1][j-1]);

                for(auto &p : prev) {
                    if(p.first == -1) continue;

                    if(p.first > maxScore) {
                        maxScore = p.first;
                        ways = p.second;
                    }
                    else if(p.first == maxScore) {
                        ways = (ways + p.second) % MOD;
                    }
                }

                if(maxScore == -1) continue;

                int val = 0;
                if(board[i][j] != 'E' && board[i][j] != 'S') {
                    val = board[i][j] - '0';
                }

                dp[i][j] = {maxScore + val, ways};
            }
        }

        auto [score, ways] = dp[n-1][n-1];

        if(score == -1) return {0, 0};

        return {score, ways};
    }
};