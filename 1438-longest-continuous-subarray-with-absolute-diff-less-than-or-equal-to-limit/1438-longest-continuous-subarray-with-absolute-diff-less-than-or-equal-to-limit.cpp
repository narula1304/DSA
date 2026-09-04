class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxlen = 0;

        int left =  0;
        int right = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        priority_queue<pair<int,int>> maxheap;

        while(right < nums.size()){
            minheap.push({nums[right],right});

            maxheap.push({nums[right],right});

            while(maxheap.top().first - minheap.top().first > limit){
                int ind = min(minheap.top().second,maxheap.top().second);
                left = ind + 1;

                while(maxheap.top().second < left){
                    maxheap.pop();
                }

                while(minheap.top().second < left){
                    minheap.pop();
                }
            }

            maxlen = max(maxlen,right-left+1);

           

            right++;


        }

        return maxlen;

    }
};