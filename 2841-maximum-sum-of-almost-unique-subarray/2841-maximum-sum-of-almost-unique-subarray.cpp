class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();

        long long maxi = 0;
        int right = 0;
        int left = 0;
        long long sum = 0;
        unordered_map<int,int> mpp;


        while(right < nums.size()){
            sum += nums[right];
            mpp[nums[right]]++;
            
            
            if(right-left+1 > k){
                sum -= nums[left];
                mpp[nums[left]]--;

                if(mpp[nums[left]] == 0){
                    mpp.erase(nums[left]);
                }

                left++;
            }

            if(right-left+1 == k && mpp.size() >= m){
                maxi = max(maxi,sum);
            }

            right++;

            
        }

        return maxi;
    }
};