class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        
        while (num > 0) {
            res += (num & 1 ? 2 : 1);
            num >>= 1;
        }
        
        return res - 1;
    }
};