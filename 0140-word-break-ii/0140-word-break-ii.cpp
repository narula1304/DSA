class Solution {
public:
    vector<string> ans;

    void solve(string s,unordered_set<string>& st,int ind,string str){
        if(ind >= s.size()){
            ans.push_back(str);
            return;
        }

        for(int i=ind;i<s.size();i++){
            string substring = s.substr(ind,i-ind+1);
            if(st.find(substring) != st.end()){
                string temp = str;

                if(!str.empty()) str += " ";
                str += substring;

                solve(s,st,i+1,str);

                str = temp; 
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());

        string str = "";

        solve(s,st,0,str);

        return ans;
    }
};