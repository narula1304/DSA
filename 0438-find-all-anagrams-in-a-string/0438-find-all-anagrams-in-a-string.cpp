class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        int m = s.size();

        int left = 0;
        int right = 0;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        vector<int> ans;

        for(int i=0;i<p.size();i++){
            freq2[p[i] - 'a']++;
        }

        while(right < m){
            freq1[s[right]-'a']++;

            if(right - left + 1 > n){
                freq1[s[left] - 'a']--;
                left++;
            }

            if(right - left + 1 == n){
                bool flag = true;
                for(int i=0;i<26;i++){
                    if(freq1[i] != freq2[i]){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    ans.push_back(left);
                }
            }

            right++;
        }

        return ans;
    }
};