class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxlen = 0;
        int n = s.size();

        int left = 0;
        int cost = 0;

        for(int right=0;right<n;right++){
            int c1 = s[right]-'a';
            int c2 = t[right]-'a';
            cost += abs(c1-c2);

            while(cost > maxCost){
                int c3 = s[left] - 'a';
                int c4 = t[left] - 'a';
                cost -= abs(c3-c4);
                left++;
            }

            maxlen = max(maxlen,right-left+1);
        }

        return maxlen;
    }
};