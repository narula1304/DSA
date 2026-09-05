class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int target = n/4;

        unordered_map<char,int> mpp;

        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }

          if (mpp['Q'] == target &&
            mpp['W'] == target &&
            mpp['E'] == target &&
            mpp['R'] == target) {
            return 0;
        }

        int left = 0;
        int ans = n;

        for(int right=0;right<n;right++){
            mpp[s[right]]--;

            while( left <= right && mpp['Q'] <= target && mpp['R'] <= target && mpp['E'] <= target && mpp['W'] <= target){
                ans = min(ans,right-left+1);
                mpp[s[left]]++;
                left++;
            }


        }

        return ans;
    }
};


// The main idea

// cnt stores the characters outside the current window.

// When we expand the window:

// cnt[s[right]]--;

// we are saying: this character is now inside the replacement window.

// When:

// cnt['Q'] <= target &&
// cnt['W'] <= target &&
// cnt['E'] <= target &&
// cnt['R'] <= target

// the outside portion is valid. Therefore, we can replace the current window with the missing characters.

// Then we shrink the window to find the minimum possible length.

// Time: O(n)
// Space: O(1) (only 4 relevant characters)