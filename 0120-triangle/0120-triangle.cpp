class Solution {
public:

    int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==triangle.size()-1) return triangle[triangle.size()-1][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + f(i+1,j,triangle,dp);
        int dia = triangle[i][j] + f(i+1,j+1,triangle,dp);

        return dp[i][j] = min(down,dia);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        // tabulation
        // base case
        // for i=n-1 j can vary from 0 to n which are all base cases
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        // in recursion we goes from 0 to n-1
        // in tabulation we go opposite from n-2 to 0
        for(int i=n-2;i>=0;i--){
            // for every i how the j varies think in your mind
            // for ex if i=0 then j can be 0 if i=1 then j can be 0,1 if i=2 then j can be 0,1,2
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int dia = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,dia);
            }
        }

        return dp[0][0];


    }
};