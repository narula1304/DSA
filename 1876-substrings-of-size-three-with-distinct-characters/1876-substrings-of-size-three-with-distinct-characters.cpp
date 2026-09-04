class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();

        int left = 0;
        int right = 0;
        int cnt = 0;

        while(right < n){

            if(right-left+1 > 3){
                left++;
            }

            if(right-left+1 == 3){
                if(s[left] != s[left+1] && s[left+1] != s[right] && s[left] != s[right]) cnt++;
            }

            right++;
        }

        return cnt;
    }
};