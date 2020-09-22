class Solution {
    
    int getNext(int n) {
        int res = 0;
        
        while (n > 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return res;
    }
    
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        while (slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return fast == 1;
    }
};