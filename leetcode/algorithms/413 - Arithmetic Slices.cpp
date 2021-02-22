class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, dp = 0;
        
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp++;
                res += dp;
            }
            else dp = 0;
        }
        
        return res;
    }
};