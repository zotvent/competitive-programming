class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int mod = (int) 1e9 + 7;
        int n = (int) A.size();
        
        unordered_map<int, int> m;
        vector<long long> dp(n, 1);
        int right;
        
        sort(A.begin(), A.end());
        
        for (int i = 0; i < n; i++) {
            m[A[i]] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] % A[j] == 0) { // A[j] is left child
                    right = A[i] / A[j]; // right if right child
                    
                    if (m.count(right) > 0) {
                        dp[i] = (dp[i] + dp[j] * dp[m[right]]) % mod;
                    }
                }
            }
        }
        
        long long res = 0;
        for (auto i: dp) res += i % mod;
        return (int) (res % mod);
    }
};