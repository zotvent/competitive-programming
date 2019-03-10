class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int res = -1;
        
        vector<int> a(6, 0), b(6, 0);
        
        int size = A.size();
        
        for (int i = 0; i < size; i++) {
            a[A[i] - 1]++;
            b[B[i] - 1]++;
        }
        
        for (int i = 0; i < 6; i++) {
            if (a[i] + b[i] >= size) {
                int tmp = calc(A, B, a, b, i);
                
                if (tmp != -1) {
                    res = (res == -1 ? tmp : min(res, tmp));    
                }
            }
        }
        
        return res;
    }
    
    int calc(vector<int>& A, vector<int>& B, vector<int>& a, vector<int>& b, int index) {
        int res = 0;
        
        if (a[index] < b[index]) {
            return calc(B, A, b, a, index);
        }
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != index + 1) {
                if (B[i] == index + 1) {
                    res++;
                }
                else {
                    res = -1;
                    break;
                }
            }
        }
        
        return res;
    }
};