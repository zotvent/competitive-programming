class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        
        int res = 0;
        int inc = 0, dec = 0;
        
        if (A[1] > A[0]) inc = 1;
        else if (A[1] < A[0]) dec = 1;
        
        for (int i = 1; i < A.size(); i++) {
            if (A[i] == A[i - 1]) {
                inc = dec = 0;
            }
            else if (A[i - 1] < A[i]) {
                if (dec > 0) {
                    inc = 2;
                    dec = 0;
                }
                else if (inc == 0) {
                    inc = 2;
                    dec = 0;
                }
                else {
                    inc++;
                }
            }
            else {
                if (inc > 0) {
                    dec++;
                }
                else {
                    inc = dec = 0;
                }
            }
            
            if (inc + dec > 2 && inc > 0 && dec > 0) {
                res = max(res, inc + dec);
            }
        }
        
        return res;
    }
};