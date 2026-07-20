class Solution {
public:

    bool solve(int k,vector<vector<int>>& queries,vector<int>& nums){
        int n = nums.size();
        vector<int> diff(n,0);

        for(int i=0;i<=k;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;
            if(r + 1 < n) diff[r+1] -= val;
        }

        for(int i=1;i<n;i++){
            diff[i] += diff[i-1];
        }

        for(int i=0;i<n;i++){
            if(nums[i] > diff[i]) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
                bool all_zero = true;
        for (int x : nums) {
            if (x > 0) {
                all_zero = false;
                break;
            }
        }
        if (all_zero) return 0;

        int low = 0;
        int high = queries.size() - 1;

        int ans = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(solve(mid,queries,nums)){
                high = mid - 1;
                ans = mid+1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};