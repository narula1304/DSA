class Solution {
public:
    // example : [5 11 20 20] k = 5 op = 1
    // for 5 i can convert it into any of the value from [0,10] by doing [5-k,5+k]
    // simi for other elements [6,16] [15,25] [15,25]
    // 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25
    // these are elements which can come in my array
    // out of them only 15 and 16 can come 3 times which is maxm by performing op on 11,20,20
    // so lets say we take 15
    // int maxcnt = 3;
    // int eleownfreq = 0
    // int needconversion = maxcnt - elewonfreq = 3-0 = 3
    // int mini = min(needconversion,numoperation) = min(3,1) = 1
    // int totalfreq = eleownfreq + mini = 0 + 1 = 1

    // so to know that 15 and 16 can comes 3 times in array we difference array concept
    // by like if curr ele = 5 so range [5-k,5+k]
    // diff[5-k] += 1;
    // diff[5+k+1] -= 1;
    // then do it for every element
    // then take cumulative sum
    // so by these arr we can find which element can come max no of times

    // now my index of difference arr here is working as values
    // so the size of diff arr maxm can be max_element(nums) + k
    
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maximumval = *max_element(nums.begin(),nums.end());
        int maxval = maximumval + k;

        unordered_map<int,int> mpp; // element,freq

        vector<int> diff(maxval+2,0);

        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            mpp[val]++;
            int l = max(0,nums[i] - k); // if a element can go neg it means it can go 0 also 
            int r = min(maxval,nums[i] + k);

            diff[l] += 1;
            if(r+1 < diff.size()) diff[r+1] -= 1;
        }

        int maxi = 0;

        for(int i=0;i<diff.size();i++){
            if(i>0) diff[i] += diff[i-1];

            int maxfreq = diff[i];
            int elementownfreq = mpp[i];
            int needconversion = maxfreq - elementownfreq;
            int mini = min(needconversion,numOperations);

            int ans = elementownfreq + mini;

            maxi = max(maxi,ans);
        }

        return maxi;

    }
};