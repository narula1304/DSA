class Solution {
public:
    int m = 1e9 + 7;
    
    int maxPerformance(int n, vector<int>& speed,
                       vector<int>& efficiency, int k) {

        vector<pair<int,int>> temp;

        for(int i = 0; i < n; i++) {
            temp.push_back({efficiency[i], speed[i]});
        }

        sort(temp.begin(), temp.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.first > b.first;
             });

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++) {

            int eff = temp[i].first;
            int s = temp[i].second;

            pq.push(s);
            sum += s;

            if(pq.size() > k) {
                int it = pq.top();
                pq.pop();

                sum -= it;      
            }

            
            ans = max(ans, sum * eff);
            
        }

        return ans % m;
    }
};