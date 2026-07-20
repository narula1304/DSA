class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        vector<int> diff(n,0);

        for(int i=0;i<shifts.size();i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dirn = shifts[i][2];

            if(dirn == 1){
                diff[start] += 1;
                if(end + 1 < n) diff[end+1] -= 1;
            }else{
                diff[start] -= 1;
                if(end + 1 < n) diff[end+1] += 1;
            }
        }

        for(int i=1;i<n;i++){
            diff[i] += diff[i-1];
        }

        for(int i=0;i<n;i++){
            s[i] = (char)('a' + (s[i] - 'a' + diff[i]%26 + 26) % 26);
        }

        return s;
    }
};