class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;
        long long factor = 1;
        while(n != 0){
            long long digit = n%10;
            if(digit!=0){
                sum += digit;
                num = num + digit*factor;
                factor = factor * 10;
            }

            n = n/10;
        }

        return sum*num;
    }
};