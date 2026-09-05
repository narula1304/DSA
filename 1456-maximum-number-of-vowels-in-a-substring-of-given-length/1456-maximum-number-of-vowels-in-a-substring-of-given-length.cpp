class Solution {
public:

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int cnt = 0;
        int n = s.size();

        int left = 0;
        int maxi = 0;
        int right = 0;

        while(right < n){
            if(isVowel(s[right])) cnt++;


            while(right-left+1 > k){
                if(isVowel(s[left])) cnt--;
                left++;
            }

            if(right-left+1 == k) maxi = max(maxi,cnt);

            right++;
        }

        return maxi;
    }
};