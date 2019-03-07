// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int res;
        
        int l = 1;
        int r = n;
        
        while (l <= r) {
            int m = (r - l) / 2 + l;
            
            if (isBadVersion(m)) {
                res = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return res;
    }
};