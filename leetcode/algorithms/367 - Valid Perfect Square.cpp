class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1;
        long long r = num;
        long long tmp = num;
        
        while (l <= r) {
            long long m = (l + r) / 2;
            long long square = m * m;
            
            if (square == tmp) {
                return true;
            }
            else if (square < tmp) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        return false;
    }
};