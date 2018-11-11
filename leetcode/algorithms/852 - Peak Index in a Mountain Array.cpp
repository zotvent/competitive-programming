class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0;
        int r = A.size() - 1;
        int res = 0;
        
        while (l <= r && !res) {
            int m = (l + r) / 2;
            if (A[m - 1] < A[m] && A[m] > A[m + 1])
                res = m;
            else if (A[m - 1] < A[m] && A[m] < A[m + 1])
                l = m + 1;
            else r = m - 1;
        }
        
        return res;
    }
};