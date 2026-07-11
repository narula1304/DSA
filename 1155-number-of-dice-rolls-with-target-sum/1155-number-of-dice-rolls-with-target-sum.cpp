class Solution {
public:
    int dp[31][1001];
    int mod = 1e9+7;

    int solve(int n,int k,int target){
        if(target < 0) return 0;
        if(n == 0) return (target == 0);

        if(dp[n][target] != -1) return dp[n][target];

        int ways = 0;
        for(int face=1;face<=k;face++){
            ways = (ways + solve(n-1,k,target-face) )% mod;
        }

        return dp[n][target] =  ways;
    }

    int numRollsToTarget(int n, int k, int target) {
       vector<vector<int>> dp(n+1,vector<int>(target+1,0));

       dp[0][0] = 1;

       for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                int ways = 0;

                for(int face = 1;face<=k;face++){
                    if(j>= face)
                    ways = (ways + dp[i-1][j-face]) % mod;
                }

                dp[i][j] = ways;
            }
       }

       return dp[n][target];
    }
};