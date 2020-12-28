class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        const int n = A.size();
        sort(A.begin(), A.end());
        int res = A[n - 1] - A[0];
        int low, high;
        
        for (int i = 0; i < n - 1; i++) {
            low = min(A[0] + K, A[i + 1] - K);
            high = max(A[n-1] - K, A[i] + K);
            res = min(res, high - low);
        }
        
        return res;
    }
};