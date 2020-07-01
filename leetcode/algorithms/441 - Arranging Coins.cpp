class Solution {
public:
    int arrangeCoins(int n) {
        int res = 0;
        
        int l = 0;
        int r = n;
        int m;
        long long sum;
        
        while (l <= r) {
            m = l + (r - l) / 2;
            sum = (1L + m) * m / 2L;
            
            if (sum <= n) {
                res = max(res, m);
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        return res;
    }
};