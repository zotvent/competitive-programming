class NumMatrix {
    vector<vector<int>> sum;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        sum = matrix;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                sum[i][j] += sum[i][j - 1];
            }
        }
        
        for (int i = 0; i < cols; i++) {
            for (int j = 1; j < rows; j++) {
                sum[j][i] += sum[j - 1][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int all = sum[row2][col2];
        int top = (row1 > 0 ? sum[row1 - 1][col2] : 0);
        int left = (col1 > 0 ? sum[row2][col1 - 1] : 0);
        int topLeft = (row1 > 0 && col1 > 0 ? sum[row1 - 1][col1 - 1] : 0);
        return all - top - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */