/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    
    bool isCelebrity(int candidate, int n) {
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (knows(candidate, i) || !knows(i, candidate)) {
                return false;
            }
        }
        return true;
    }
    
public:
    int findCelebrity(int n) {
        for (int i = 0; i < n; i++) {
            if (isCelebrity(i, n)) {
                return i;
            }
        }
        return -1;
    }
};