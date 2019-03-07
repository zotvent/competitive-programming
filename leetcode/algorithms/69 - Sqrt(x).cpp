class Solution {
public:
    int mySqrt(int x) {
        int res;
        
        int l = 0;
        int r = x;
        
        while (l <= r) {
            long long m = (r - l) / 2 + l;
            long long square = m * m;
            
            if (square == x) {
                res = m;
                break;
            }
            else if (square > x) {
                r = m - 1;
            }
            else {
                res = m;
                l = m + 1;
            }
        }
        
        return res;
    }
};