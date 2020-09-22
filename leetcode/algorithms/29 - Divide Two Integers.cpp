class Solution {
public:
    int divide(int dividend, int divisor) {        
        long long res = 0;
        long long num = dividend;
        long long div = divisor;
        bool positive = (num >= 0 && div > 0) || (num < 0 && div < 0);
        
        num = abs(num);
        div = abs(div);
        
        if (div > 1) {
            long long cur, value;
            
            while (num >= div) {
                cur = 1;
                value = div;
                
                while (value + value <= num) {
                    cur += cur;
                    value += value;
                }
                
                res += cur;
                num -= value;
            }
        }
        else {
            res = num;
        }
        
        if (!positive) {
            res = -res;
        }
        
        return (res > INT_MAX) ? INT_MAX : res;
    }
};