class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increasing = true;
        bool decreasing = true;
        
        for (int i = 1; i < A.size(); i++) {
            if (increasing && A[i] < A[i - 1]) increasing = false;
            if (decreasing && A[i] > A[i - 1]) decreasing = false;
        }
        
        return increasing || decreasing;
    }
};