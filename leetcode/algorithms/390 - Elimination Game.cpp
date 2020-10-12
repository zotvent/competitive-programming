class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, step = 1;
        int remaining = n;
        bool moveToRight = true;
        
        while (remaining > 1) {
            if (moveToRight || remaining % 2 == 1) {
                head += step;
            }
            
            remaining /= 2;
            step *= 2;
            moveToRight = !moveToRight;
        }
        
        return head;
    }
};