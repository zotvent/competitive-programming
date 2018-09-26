class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int res = 0;
        int mn = A[0];
        int mx = A[0];

        for (int i = 0; i < A.size(); i++) {
            if (A[i] > mx) mx = A[i];
            if (A[i] < mn) mn = A[i];
        }

        if (mx - mn >= 2 * K) 
            res = mx - mn - 2 * K;

        return res;
    }
};