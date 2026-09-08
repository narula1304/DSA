class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int,int>> temp;

        for(int i = 0; i < n; i++) {
            temp.push_back({nums2[i], nums1[i]});
        }

        // Sort by nums2 in decreasing order
        sort(temp.begin(), temp.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.first > b.first;
             });

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++) {

            int second = temp[i].first;
            int first = temp[i].second;

            // Add nums1 value
            pq.push(first);
            sum += first;

            // Keep only k largest nums1 values
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            // Once we have k elements
            if(pq.size() == k) {
                ans = max(ans, sum * second);
            }
        }

        return ans;
    }
};