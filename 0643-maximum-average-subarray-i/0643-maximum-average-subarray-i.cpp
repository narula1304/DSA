class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = -1e9;

        int left = 0;
        int right = 0;
        double sum = 0.0;


        while(right < nums.size()){
            sum += (double)nums[right];

            int len = right - left + 1;

            if(len == k){
                avg = max(avg,double(sum/len));
                sum -= nums[left];
                left++;
            }

            right++;
        }
        
        return avg;
    }
};