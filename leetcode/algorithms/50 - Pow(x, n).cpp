class Solution {
    
    double fastPow(double x, long long n) {
        if (n == 0) return 1;
        
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        }
        else {
            return half * half * x;
        }
    }
    
public:
    double myPow(double x, int n) {
        long long N = n;
        
        if (N < 0) {
            N = -N;
            x = 1 / x;
        }
        
        return fastPow(x, N);
    }
};