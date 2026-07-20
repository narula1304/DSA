class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       vector<int> pass(1001,0);

       for(int i=0;i<trips.size();i++){
            int from = trips[i][1];
            int to = trips[i][2];
            int num = trips[i][0];

            pass[from] += num;
            if(to < 1001) pass[to] -= num;
       }

       if(pass[0] > capacity) return false;

       for(int i=1;i<1001;i++){
        pass[i] += pass[i-1];
        if(pass[i] > capacity) return false;
       }

       return true;
    }
};