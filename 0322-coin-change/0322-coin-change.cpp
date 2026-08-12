class Solution {
public:

    int f(int index,int target,vector<int>& coins,vector<vector<int>>& dp){
        // base case
        // if i reach the index == 0 then if the target%coin[0] == 0
        // then i will return target/arr[0] else i will return 1e9

        if(index == 0){
            if(target%coins[0] == 0){
                return target/coins[0];
            }else{
                return 1e9;
            }
        }

        if(dp[index][target] != -1) return dp[index][target];

        // pick or nonpick
        int nottake = 0 + f(index-1,target,coins,dp);
        int take = 1e9;
        if(coins[index] <= target){
            take = 1 + f(index,target-coins[index],coins,dp);
        }

        return dp[index][target] = min(take,nottake);

    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        

        for(int j=0;j<=amount;j++){
            if(j%coins[0] == 0){
                dp[0][j] = j/coins[0];
            }else{
                dp[0][j] = 1e9;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int nottake = dp[i-1][j];
                int take = 1e9;
                if(coins[i] <= j){
                    take = 1 + dp[i][j-coins[i]];
                }
                dp[i][j] = min(take,nottake);
            }
        }

        return (dp[n-1][amount] >= 1e9) ? -1 : dp[n-1][amount];
    }
};