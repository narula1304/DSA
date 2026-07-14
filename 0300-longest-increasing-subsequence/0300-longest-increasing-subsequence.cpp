class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        // idx/i -> n-1 to 0
        // j(previdx) -> n-1 to -1 but the correct is idx-1 to -1
       
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int nottake = 0 + dp[i+1][j+1];
                int take = 0;
                if(j == -1 || nums[i] > nums[j]){
                    take = 1 + dp[i+1][i+1];
                }

                dp[i][j+1] = max(take,nottake);
            }
        }

        return dp[0][-1+1];
    }
};