class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }
        
        int res = N, i = 0;
        
        while ((1 << i) <= N) {
            res ^= (1 << i++);
        }
        
        return res;
    }
};