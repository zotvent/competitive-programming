class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> res = mat;
        const int rows = mat.size();
        const int cols = mat[0].size();
        const int inf = (int) 1e8;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (res[i][j] == 1) {
                    res[i][j] = inf;
                }
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i > 0) res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                if (j > 0) res[i][j] = min(res[i][j], res[i][j - 1] + 1);
            }
        }
        
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1) res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                if (j < cols - 1) res[i][j] = min(res[i][j], res[i][j + 1] + 1);
            }
        }
        
        return res;
    }
};