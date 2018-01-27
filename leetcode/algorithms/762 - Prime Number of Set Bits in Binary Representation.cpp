class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; i++) 
            if (isPrime(i)) res++;
        return res;
    }
    
    bool isPrime(int x) {
        int n = countSetBits(x);
        if (n < 2) return false;
        else if (n == 2) return true;
        for (int i = 2; i*i <= n; i++)
            if (n%i == 0) return false;
        return true;
    }
    
    int countSetBits(int x) {
        int res = 0;
        while (x > 0) {
            res += (x & 1);
            x >>= 1;
        }
        return res;
    }
};