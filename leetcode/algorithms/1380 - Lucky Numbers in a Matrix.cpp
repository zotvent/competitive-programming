class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        
        vector<int> rowMin;
        vector<int> colMax;
        
        int rows = matrix.size();
        int cols = (matrix.empty() ? 0 : matrix[0].size());
        
        int mx, mn;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (j == 0) mn = matrix[i][j];
                else mn = min(mn, matrix[i][j]);
                
                if (j == cols - 1) {
                    rowMin.push_back(mn);
                }
            }
        }
        
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                if (j == 0) mx = matrix[j][i];
                else mx = max(mx, matrix[j][i]);
                
                if (j == rows - 1) {
                    colMax.push_back(mx);
                }
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        
        return res;
    }
};