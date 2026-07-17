class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int basesum = 0;

        for(int i=0;i<customers.size();i++){
            if(grumpy[i] == 0){
                basesum += customers[i];
            }
        }

        int left = 0;
        int right = 0;

        int extrasum = 0;
        int maxextrasum = 0;

        while(right < grumpy.size()){
            if(grumpy[right] == 1){
                extrasum += customers[right];
            }

            if(right - left + 1 == minutes){
                maxextrasum = max(maxextrasum,extrasum);
                if(grumpy[left] == 1) extrasum -= customers[left];
                left++;
            }

            right++;
        }

        return basesum + maxextrasum;
    }
};