class Solution {
public:
    vector<vector<string>> ans;

    bool ispalin(string s){
        int i = 0;
        int j = s.size() - 1;

        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(string s,int ind,vector<string>& str){

        if(ind == s.size()){
            ans.push_back(str);
            return;
        }

        for(int i=ind;i<s.size();i++){

            string substring = s.substr(ind,i-ind+1);

            if(ispalin(substring)){
                str.push_back(substring);
                solve(s,i+1,str);
                str.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> str;
        solve(s,0,str);

        return ans;
    }
};