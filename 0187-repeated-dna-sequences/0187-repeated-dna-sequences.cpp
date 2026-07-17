class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_map<string,int> mpp;
        unordered_set<string> ans;

        string str="";
        int left=0;

        for(int right=0; right<s.size(); right++){

            str += s[right];

            if(right-left+1==10){

                mpp[str]++;

                if(mpp[str] == 2)
                    ans.insert(str);
                    
                str.erase(0,1);
                left++;
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};