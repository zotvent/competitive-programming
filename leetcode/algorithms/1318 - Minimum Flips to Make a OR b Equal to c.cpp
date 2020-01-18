class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        
        int la, lb, lc;
        
        while (a > 0 || b > 0 || c > 0) {
            la = a & 1;
            lb = b & 1;
            lc = c & 1;
                        
            if (lc == 1 && la == 0 && lb == 0) {
                res++;
            }
            else if (lc == 0) {
                res += la + lb;
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return res;
    }
};