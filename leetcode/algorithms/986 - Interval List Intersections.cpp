class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        
        int l = 0;
        int r = 0;
        int left, right;
        
        while (l < A.size() && r < B.size()) {
            left = max(A[l][0], B[r][0]);
            right = min(A[l][1], B[r][1]);
            
            if (left <= right) {
                res.push_back({left, right});
            }
            
            if (A[l][1] < B[r][1]) l++;
            else r++;
        }
        
        return res;
    }
};