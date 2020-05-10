class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        
        int pos = 0;
        int neg;
        
        while (pos < A.size() && A[pos] < 0) {
            pos++;
        }
        neg = pos - 1;
        
        while (neg >= 0 || pos < A.size()) {
            if (neg < 0) {
                while (pos < A.size()) {
                    res.push_back(A[pos] * A[pos]);
                    pos++; 
                }
            }
            else if (pos == A.size()) {
                while (neg >= 0) {
                    res.push_back(A[neg] * A[neg]);
                    neg--;
                }
            }
            else if (A[neg] * A[neg] <= A[pos] * A[pos]) {
                res.push_back(A[neg] * A[neg]);
                neg--;
            }
            else {
                res.push_back(A[pos] * A[pos]);
                pos++; 
            }
        }
        
        return res;
    }
};