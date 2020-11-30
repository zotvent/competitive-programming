class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        int cur;
        
        while (n > 0) {
            cur = n & 1;
            if (cur == prev) {
                return false;
            }
            prev = cur;
            n >>= 1;
        }
        
        return true;
    }
};