class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> divisors;
        int sqrtN = (int) sqrt(n);
        
        for (int i = 1; i < sqrtN + 1; i++) {
            if (n % i == 0) {
                k--;
                divisors.push_back(i);
                if (k == 0) {
                    return i;
                }
            }
        }
        
        if (sqrtN * sqrtN == n) {
            k++;
        }
        
        int size = divisors.size();
        return (k <= size ? n / divisors[size - k] : -1);
    }
};