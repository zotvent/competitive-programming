class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int res = 0;
        
        for (int i = 0; i < A.size(); i++)
            if (A[res] < A[i])
                res = i;
        
        return res;
    }
};