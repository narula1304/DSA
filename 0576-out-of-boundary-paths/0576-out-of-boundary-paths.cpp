class Solution {
public:
    vector<pair<int,int>> dirn = {{-1,0},{0,1},{0,-1},{1,0}};
    int mod = 1e9 + 7;
    int dp[51][51][51];

    int solve(int m, int n, int maxMove, int row, int col) {
        if (row >= m || col >= n || row < 0 || col < 0) {
            return 1;
        }

        if (maxMove == 0)
            return 0;

        if(dp[row][col][maxMove] != -1) return dp[row][col][maxMove];

        long long cnt = 0;

        for (auto it : dirn) {
            int dx = row + it.first;
            int dy = col + it.second;

            cnt = (cnt + solve(m, n, maxMove - 1, dx, dy)) % mod;
        }

        return dp[row][col][maxMove] =  cnt;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        
        return solve(m, n, maxMove, startRow, startColumn);
    }
};