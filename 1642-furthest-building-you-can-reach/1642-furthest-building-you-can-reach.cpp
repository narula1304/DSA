class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int sum = 0;
        priority_queue<int,vector<int>,greater<int>> pq;


        int i = 0;

        while(i<heights.size() - 1){

             if(heights[i+1] > heights[i]){

                pq.push(heights[i+1]-heights[i]);

                if(pq.size() > ladders){
                    sum += pq.top();
                    pq.pop();
                    if(sum > bricks){
                        break;
                    }
                }

            }

            i++;

        }

        return i;



    }
};