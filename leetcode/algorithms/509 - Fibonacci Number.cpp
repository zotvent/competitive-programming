class Solution {
public:
    int fib(int N) {
        if (N < 2) return N;
        
        vector<int> f = {0, 1};
        int tmp;
        
        for (int i = 2; i <= N; i++) {
            tmp = f[0] + f[1];
            f[0] = f[1];
            f[1] = tmp;
        }
        
        return f[1];
    }
};