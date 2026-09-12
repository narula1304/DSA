class Solution { 
public: 
 
    struct Node { 
        long long score = 0; 
        vector<int> idxs; 
    }; 
 
    vector<int> nextidx; 
    vector<vector<Node>> dp; 
 
    int findNext(vector<vector<int>>& temp, int start, int r){ 
        int l = start; 
        int right = temp.size() - 1; 
        int result = temp.size(); 
 
        while(l <= right){ 
            int mid = l + (right - l) / 2; 
            
            if(temp[mid][0] > r){ 
                result = mid; 
                right = mid - 1; 
            }else{ 
                l = mid + 1; 
            } 
        } 
 
        return result; 
    } 
 
    Node solve(vector<vector<int>>& intervals, int idx, int k){ 
         
        if(k == 0 || idx == intervals.size()) 
            return Node(); 
 
        if(dp[idx][k].score != -1) 
            return dp[idx][k]; 
 
        Node skip = solve(intervals, idx + 1, k); 
 
        int wt = intervals[idx][2]; 
        int ind = intervals[idx][3]; 
        int j = nextidx[idx]; 
 
        Node temp = solve(intervals, j, k - 1); 
 
        Node take; 
        take.score = temp.score + wt; 
        take.idxs = temp.idxs; 
        take.idxs.push_back(ind); 
        sort(take.idxs.begin(), take.idxs.end());
 
        Node result; 
 
        if(skip.score > take.score){ 
            result = skip; 
        } 
        else if(skip.score < take.score){ 
            result = take; 
        } 
        else{ 
            result = (skip.idxs < take.idxs) ? skip : take; 
        } 
 
        return dp[idx][k] = result; 
    } 
 
    vector<int> maximumWeight(vector<vector<int>>& intervals) { 
        int n = intervals.size(); 
        vector<vector<int>> temp; 
 
        for(int i = 0; i < n; i++){ 
            vector<int> t = intervals[i]; 
            t.push_back(i); 
            temp.push_back(t); 
        } 
 
        // Sort by left endpoint
        sort(temp.begin(), temp.end()); 
 
        nextidx.resize(n); 
 
        for(int i = 0; i < n; i++){ 
            int end = temp[i][1]; 
            nextidx[i] = findNext(temp, i + 1, end); 
        } 
 
        dp.assign(n, vector<Node>(5)); 
 
        for(int i = 0; i < n; i++){
            for(int k = 0; k <= 4; k++){
                dp[i][k].score = -1;
            }
        }
 
        int k = 4; 
 
        return solve(temp, 0, k).idxs; 
    } 
};