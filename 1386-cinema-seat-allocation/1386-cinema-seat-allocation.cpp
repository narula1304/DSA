class Solution { 
public: 
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) { 
        unordered_map<int,set<int>> mpp; 
        
        for(auto it : reservedSeats){ 
            int rowno = it[0]; 
            int seatno = it[1]; 
            mpp[rowno].insert(seatno); 
        } 

        int ans = (n - mpp.size()) * 2;

        for(auto it : mpp){ 
            int rowno = it.first; 
            set<int> seatnos = it.second; 

            bool left = true;
            bool right = true;
            bool middle = true;

            for(int seat : seatnos) {
                if(seat >= 2 && seat <= 5)
                    left = false;

                if(seat >= 6 && seat <= 9)
                    right = false;

                if(seat >= 4 && seat <= 7)
                    middle = false;
            }

            if(left && right)
                ans += 2;
            else if(left || right || middle)
                ans += 1;
        }

        return ans;
    } 
};