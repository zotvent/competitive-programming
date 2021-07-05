class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        const int rows = mat.size();
        const int cols = mat[0].size();
        
        if (rows * cols != r * c) return mat;
        
        vector<vector<int>> res(r, vector<int>(c));
        int cnt = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[cnt / c][cnt % c] = mat[i][j];
                cnt++;
            }
        }
        
        return res;
    }
};