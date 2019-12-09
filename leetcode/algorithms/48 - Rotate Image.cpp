class Solution {
public:
    void rotate(vector< vector<int> >& matrix) {
        int n = matrix.size();

        // swap by main diagonal
        int row = 0;
        int col = n - 1;
        for (; row < n; row++) {
            for (int c = 0; c < col; c++) {
                swap(matrix[row][c], matrix[n - 1 - c][col]);
            }
            col--;
        }

        // invert each column
        for (int c = 0; c < n; c++) {
            for (int r = 0; r < n / 2; r++) {
                swap(matrix[r][c], matrix[n - 1 - r][c]);
            }
        }
    }
};