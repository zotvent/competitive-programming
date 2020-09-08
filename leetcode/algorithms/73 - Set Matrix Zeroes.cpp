class Solution {
    
    void fillRow(vector<vector<int>>& matrix, int row, int value) {
        int cols = (matrix.empty()) ? 0 : matrix[0].size();
        
        for (int i = 0; i < cols; i++) {
            matrix[row][i] = value;
        }
    }
    
    void fillCol(vector<vector<int>>& matrix, int col, int value) {
        int rows = matrix.size();
        
        for (int i = 0; i < rows; i++) {
            matrix[i][col] = value;
        }
    }
    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = (matrix.empty()) ? 0 : matrix[0].size();
        
        bool topRowHasZero = false;
        bool leftColHasZero = false;
        
        for (int i = 0; i < cols; i++) {
            if (matrix[0][i] == 0) {
                topRowHasZero = true;
            }
        }
        
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                leftColHasZero = true;
            }
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (topRowHasZero) fillRow(matrix, 0, 0);
        if (leftColHasZero) fillCol(matrix, 0, 0);
    }
};