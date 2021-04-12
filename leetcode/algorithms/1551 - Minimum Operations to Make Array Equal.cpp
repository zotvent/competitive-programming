class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            res += abs(2 * i + 1 - n);
        }
        
        return res / 2;
    }
};