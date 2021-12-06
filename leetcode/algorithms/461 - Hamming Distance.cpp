class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, dif = x ^ y;
        
        while (dif > 0) {
            if (dif & 1) res++;
            dif >>= 1;
        }
        
        return res;
    }
};