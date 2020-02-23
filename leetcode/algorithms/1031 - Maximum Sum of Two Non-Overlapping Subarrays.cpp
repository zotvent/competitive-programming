class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> dp = A;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] += dp[i - 1];
        }
        
        int res = dp[L + M - 1];
        int Lmax = dp[L - 1];
        int Mmax = dp[M - 1];
        
        for (int i = L + M; i < dp.size(); i++) {
            Lmax = max(Lmax, dp[i - M] - dp[i - L - M]);
            Mmax = max(Mmax, dp[i - L] - dp[i - L - M]);
            res = max(res, max(Lmax + dp[i] - dp[i - M], Mmax + dp[i] - dp[i - L]));
        }
        
        return res;
    }
};