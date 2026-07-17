class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        vector<int> freq(26,0);

        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }

        int left = 0;
        int right = 0;

        vector<int> freq2(26,0);

        while(right < s1.size()-1){
            freq2[s2[right]-'a']++;
            right++;
        }

        while(right < s2.size()){

            // Include current character
            freq2[s2[right]-'a']++;

            // Compare frequencies
            if(freq == freq2) return true;

            // Remove leftmost character and slide
            freq2[s2[left]-'a']--;
            left++;
            right++;
        }

        return false;
    }
};