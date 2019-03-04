class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        
        int neg = -1;
        int pos = A.size();
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < 0) {
                neg = i;
            }
            else if (A[i] >= 0) {
                pos = i;
                break;
            }
        }
        
        while (neg >= 0 || pos < A.size()) {
            if (pos == A.size()) {
                res.push_back(A[neg] * A[neg]);
                neg--;
            }
            else if (neg < 0) {
                res.push_back(A[pos] * A[pos]);
                pos++;
            }
            else if (A[pos] * A[pos] <= A[neg] * A[neg]) {
                res.push_back(A[pos] * A[pos]);
                pos++;
            }
            else {
                res.push_back(A[neg] * A[neg]);
                neg--;
            }
        }
        
        return res;
    }
};