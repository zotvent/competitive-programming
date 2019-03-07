class Solution {
public:
    int arrangeCoins(int n) {
        int res = 0;
        long long tmp = n;
        
        long long l = 0;
        long long r = n;
        
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long sum = (m + m * m) / 2;
            
            if (sum == tmp) {
                res = m;
                break;
            }
            if (sum > tmp) {
                r = m - 1;
            }
            else {
                l = m + 1;
                res = m;
            }
        }
        
        return res;
    }
};