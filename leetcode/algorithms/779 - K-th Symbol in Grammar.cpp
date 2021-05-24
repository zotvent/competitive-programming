class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        int parent = kthGrammar(N - 1, (K + 1) / 2);
        return (K % 2 == 1) ? parent : !parent;
    }
};