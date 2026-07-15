class Solution {
public:
    vector<vector<int>> dp;

    int findmax(int i, int j, vector<int>& arr) {
        int mx = INT_MIN;
        for (int k = i; k <= j; k++) {
            mx = max(mx, arr[k]);
        }
        return mx;
    }

    int solve(vector<int>& arr, int i, int j) {
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int ind = i; ind < j; ind++) {

            int leftMax = findmax(i, ind, arr);
            int rightMax = findmax(ind + 1, j, arr);

            int cost = leftMax * rightMax
                     + solve(arr, i, ind)
                     + solve(arr, ind + 1, j);

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n, vector<int>(n, -1));

        return solve(arr, 0, n - 1);
    }
};