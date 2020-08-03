class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        int col = 0;
        int cols = (matrix.empty() ? 0 : matrix[0].size());
        
        while (row >= 0 && col < cols) {
            if (matrix[row][col] > target) {
                row--;
            }
            else if (matrix[row][col] < target) {
                col++;
            }
            else {
                return true;
            }
        }
        
        return false;
    }
};