/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    
    bool isCelebrity(int i, int n) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    int findCelebrity(int n) {
        int candidate = 0;
        
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        
        return isCelebrity(candidate, n) ? candidate : -1;
    }
};