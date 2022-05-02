class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<int> rows = {(int) mat1.size(), (int) mat2.size()};
        vector<int> cols = {(int) mat1[0].size(), (int) mat2[0].size()};
        vector<vector<int>> res(rows[0], vector<int>(cols[1]));
        
        for (int r = 0; r < rows[0]; r++) {
            for (int c = 0; c < cols[1]; c++) {
                int product = 0;
                
                for (int k = 0; k < cols[0]; k++) {
                    product += mat1[r][k] * mat2[k][c];
                }
                
                res[r][c] = product;
            }
        }
        
        return res;
    }
};