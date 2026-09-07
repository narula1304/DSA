class Solution { 
public: 
    struct cmp {
        bool operator()(const pair<int,string>& a,
                        const pair<int,string>& b) {
            
            if(a.first != b.first)
                return a.first > b.first;   
            
            return a.second < b.second;     
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) { 
        unordered_map<string,int> mpp; 
 
        for(auto it : words){ 
            mpp[it]++; 
        } 
 
        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            cmp
        > pq; 
 
        for(auto it : mpp){ 
            string word = it.first; 
            int freq = it.second; 
 
            pq.push({freq,word}); 
            
            if(pq.size() > k) 
                pq.pop(); 
        } 
 
        vector<string> ans;

        while(!pq.empty()){ 
            ans.push_back(pq.top().second);
            pq.pop();
        } 
 
        reverse(ans.begin(), ans.end());

        return ans;
    } 
};