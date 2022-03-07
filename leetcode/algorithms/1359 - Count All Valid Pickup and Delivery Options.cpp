class Solution {
public:
    int countOrders(int n) {
        long long res = 1;
        const int mod = 1e9 + 7;
        
        for (int i = 1; i <= 2 * n; i++) {
            res *= i;
            if (i % 2 == 0) {
                res /= 2;
            }
            res %= mod;
        }
        
        return res;
    }
};