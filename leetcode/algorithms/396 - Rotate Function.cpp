class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long sum = 0;
        long long sumProd = 0;
        const long long n = A.size();
        
        for (long long i = 0; i < n; i++) {
            sum += A[i];
            sumProd += A[i] * i;
        }
        
        long long res = sumProd;
        long long next;
        
        for (long long i = n - 1; i >= 0; i--) {
            next = sumProd - A[i] * n + sum;
            sumProd = next;
            res = max(res, sumProd);
        }
        
        return res;
    }
};