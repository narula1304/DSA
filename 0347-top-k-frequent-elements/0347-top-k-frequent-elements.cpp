class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> bucket(n+1);
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            int ele = it.first;
            int freq = it.second;

            bucket[freq].push_back(ele);
        }

        int idx = 0;
        vector<int> result;

        for(int i=bucket.size() - 1;i>0;i--){
            for(auto num : bucket[i]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }

        return result;
    }
};