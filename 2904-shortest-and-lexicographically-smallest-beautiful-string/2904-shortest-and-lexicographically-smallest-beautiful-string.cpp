class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int cntone = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1') {
                cntone++;
            }

            while (cntone > k) {
                if (s[left] == '1') {
                    cntone--;
                }
                left++;
            }

            while (left <= right && s[left] == '0') {
                left++;
            }

            if (cntone == k) {
                string curr = s.substr(left, right - left + 1);

                if (ans.empty() ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};