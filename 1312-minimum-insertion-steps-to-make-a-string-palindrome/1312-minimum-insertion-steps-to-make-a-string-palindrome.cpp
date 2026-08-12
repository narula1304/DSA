class Solution {
public:

    int f(int ind1,int ind2,string s,string r,vector<vector<int>> dp){
        if(ind1 < 0 || ind2 < 0) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(s[ind1] == r[ind2]){
            return dp[ind1][ind2] =  1 + f(ind1-1,ind2-1,s,r,dp);
        }

        return dp[ind1][ind2] =  0 + max(f(ind1,ind2-1,s,r,dp),f(ind1-1,ind2,s,r,dp));
    }

    int minInsertions(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        int n = s.size();
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == r[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(curr[j-1],prev[j]);
                }
            }

            prev = curr;
        }



        int l1 =  prev[n];

        return n - l1;
    }
};