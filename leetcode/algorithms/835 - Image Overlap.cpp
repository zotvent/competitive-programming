class Solution {
    
    int shiftAndCount(int rowShift, int colShift, vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0;
        int r = 0;
        int c;
        const int n = A.size();
        
        for (int row = rowShift; row < n; row++) {
            c = 0;
            
            for (int col = colShift; col < n; col++) {
                if (A[row][col] == 1 && B[r][c] == 1) {
                    res++;
                }
                c++;
            }
            
            r++;
        }
        
        return res;
    }
    
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0;
        const int n = A.size();
        
        for (int rowShift = 0; rowShift < n; rowShift++) {
            for (int colShift = 0; colShift < n; colShift++) {
                res = max(res, shiftAndCount(rowShift, colShift, A, B));
                res = max(res, shiftAndCount(rowShift, colShift, B, A));
            }
        }
        
        return res;
    }
};