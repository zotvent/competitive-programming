class Solution {
public:
    int bitwiseComplement(int N) {
        int res = (N == 0 ? 1 : 0);
        
        int i = 0;
        int powerOf2 = 1 << i;
        int tmp;
        
        while (powerOf2 <= N) {
            tmp = powerOf2 & N;
            if (!tmp) res |= powerOf2;
            ++i;
            powerOf2 = 1 << i;
        }
        
        return res;
    }
};