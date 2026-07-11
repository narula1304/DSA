class Solution {
public:
    vector<pair<int,int>> dirn = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix,int i,int j,int m,int n){

        if(dp[i][j] != -1) return dp[i][j];

        int longest = 1;

        for(auto it : dirn){
            int dx = i + it.first;
            int dy = j + it.second;

            if(dx >= 0 && dy >= 0 && dx < m && dy < n && matrix[dx][dy] > matrix[i][j])
            longest = max(longest,1+dfs(matrix,dx,dy,m,n));

        }

        return dp[i][j] =  longest;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        dp.assign(m,vector<int>(n,-1));

        int longest = 1;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                longest = max(longest,dfs(matrix,i,j,m,n));
            }
        }

        return longest;
    }
};