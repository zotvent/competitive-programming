class Solution {
    
    int numberOfDigits(int n) {
        int res = 0;
        while (n > 0) {
            n /= 10;
            res++;
        }
        return max(1, res);
    }
    
    int pow(int n, int power) {
        int res = 1;
        for (int i = 0; i < power; i++) {
            res *= n;
        }
        return res;
    }
    
public:
    bool isArmstrong(int n) {
        int sum = 0, N = n;
        int digits = numberOfDigits(n);
        
        while (N > 0) {
            sum += pow(N % 10, digits);
            N /= 10;
        }
        
        return sum == n;
    }
};