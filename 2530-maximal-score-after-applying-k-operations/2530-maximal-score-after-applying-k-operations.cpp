class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();

        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }

        long long score = 0;

        while(!pq.empty() && k--){
            int it = pq.top();
            pq.pop();

            score += it;

            it = (it+2)/3;

            pq.push(it);
        }

        return score;
    }
};