class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        int length = 0;
        const int mod = (int) 1e9 + 7;
        
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                length++;
            }
            res = ((res << length) | i) % mod;
        }
        
        return res;
    }
};