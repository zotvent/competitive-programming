class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0;
        
        int l = 0;
        int r = 0;
        int zeros = 0;
        
        while (r < A.size()) {
            zeros += A[r] == 0;
            
            while (zeros > K && l < A.size()) {
                zeros -= A[l] == 0;
                l++;
            }
            
            res = max(res, r - l + 1);
            r++;
        }
        
        return res;
    }
};