class Solution {

    static boolean solve(int num){
        int cnt = 0;

        while(num != 0){
            num = num/10;
            cnt++;
        }

        if(cnt % 2 == 0) return true;

        return false;
    }


    public int findNumbers(int[] nums) {
        int cnt = 0;

        int n = nums.length;

        for(int i=0;i<n;i++){
            if(solve(nums[i])){
                cnt++;
            }
        }

        return cnt;
    }
}