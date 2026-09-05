class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int truecnt = 0;
        int falsecnt = 0;
        int n = answerKey.size();

        int left = 0;
        int maxi = 0;
        
        for(int right=0;right<n;right++){
            if(answerKey[right] == 'T') truecnt++;
            else falsecnt++;

            while(min(truecnt,falsecnt) > k){
                if(answerKey[left] == 'T') truecnt--;
                else falsecnt--;

                left++;
            }

            maxi = max(maxi,right-left+1);
        }

        return maxi;
    }
};