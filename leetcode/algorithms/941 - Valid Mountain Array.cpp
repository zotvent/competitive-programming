class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int l = -1;
        int r = A.size();
        
        int i = 1;
        while (i < A.size() && A[i - 1] < A[i]) {
            l = i++;
        }
        
        i = (int) A.size() - 2;
        while (i >= 0 && A[i] > A[i + 1]) {
            r = i--;
        }
        
        return l == r;
    }
};