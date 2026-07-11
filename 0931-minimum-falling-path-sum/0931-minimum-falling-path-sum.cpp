class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0)); // changed from -100000 to 0 since we overwrite everything

        // tabulation
        // base case
        // i == n-1 and j can vary
        for(int j=0;j<n;j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        // for loop since i=n-1 is done we loop i from n-2 to 0
        // and for every i the j can vary from 0 to n-1

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int ld = INT_MAX;
                int rd = INT_MAX;
                int up = matrix[i][j] + dp[i+1][j];
                if(j > 0)  ld = matrix[i][j] + dp[i+1][j-1];   // fixed condition
                if(j < n-1)  rd = matrix[i][j] + dp[i+1][j+1]; // fixed condition

                dp[i][j] = min(up,min(ld,rd));
            }
        }

        // store mini as dp[0][0] and run a for loop for j from 1 to n-1
        int mini = dp[0][0];
        for(int j=1;j<n;j++){
            mini = min(mini,dp[0][j]);
        }

        return mini;
    }
};
