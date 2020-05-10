/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        
        for (int i = 0; i < n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        
        if (isCelebrity(candidate, n)) {
            return candidate;
        }
        
        return -1;
    }
    
    bool isCelebrity(int x, int n) {
        for (int i = 0; i < n; i++) {
            if (i == x) continue;
            if (knows(x, i) || !knows(i, x)) {
                return false;
            }
        }
        return true;
    } 
};