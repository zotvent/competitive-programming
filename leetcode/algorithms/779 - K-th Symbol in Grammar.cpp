class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) {
            return 0;
        }
        
        int prevK = (K + 1) / 2;
        int res = kthGrammar(N - 1, prevK);
        
        if (K % 2 == 1) {
            return res;
        }
        else {
            return (res == 0 ? 1 : 0);
        }
    }
};