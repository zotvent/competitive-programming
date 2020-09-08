// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int m;
        
        while (l < r) {
            m = l + (r - l) / 2;
            
            if (isBadVersion(m)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        
        return l;
    }
};