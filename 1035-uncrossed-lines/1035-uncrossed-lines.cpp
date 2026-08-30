class Solution {
public:

    int connectinglines(int ind1,int ind2,vector<int>& num1,vector<int>& num2,vector<vector<int>>& dp){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(num1[ind1] == num2[ind2]){
            return dp[ind1][ind2] =  1 +  connectinglines(ind1-1,ind2-1,num1,num2,dp);
        }else{
            return dp[ind1][ind2] =  0 + max(connectinglines(ind1-1,ind2,num1,num2,dp),connectinglines(ind1,ind2-1,num1,num2,dp));
        }
    }

    int maxUncrossedLines(vector<int>& num1, vector<int>& num2) {
       
        int n1 = num1.size();
        int n2 = num2.size();

        int ind1 = n1-1;
        int ind2 = n2-1;

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));

        return connectinglines(ind1,ind2,num1,num2,dp);
    }
};