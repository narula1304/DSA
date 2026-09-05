class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        int left = 0;
        long long cnt = 0;

        for (int right = 0; right < n; right++) {

            if (nums[right] == maxi)
                cnt++;

            while (cnt == k) {
                if (nums[left] == maxi)
                    cnt--;

                left++;
            }

            
                ans += left;
        }

        return ans;
    }
};