class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxlen = 0;
        int left = 0;

        multiset<int> st;

        for (int right = 0; right < nums.size(); right++) {

            st.insert(nums[right]);

            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[left]));
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};