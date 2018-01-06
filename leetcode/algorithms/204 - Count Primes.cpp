class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        
        int res = 1;
        int upper = sqrt(n);
        vector<bool> used(n);
        for (int i = 3; i < n; i += 2) {
            if (!used[i]) {
                res++;
                if (i > upper) continue;
                for (int j = i*i; j < n; j += i)
                    used[j] = true;
            }
        }
        return res;
    }
};