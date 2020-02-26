class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        
        int rows = mat.size();
        int cols = (mat.empty() ? 0 : mat[0].size());
        
        for (int col = 0; col < cols; col++) {
            for (int row = 0; row < rows; row++) {
                if (mat[row][col] == 0 && (col == 0 || mat[row][col - 1] == 1) && res.size() < k) {
                    res.push_back(row);
                }
            }
        }
        
        for (int row = 0; row < rows; row++) {
            if (mat[row][cols - 1] == 1 && res.size() < k) {
                res.push_back(row);
            }
        }
        
        return res;
    }
};