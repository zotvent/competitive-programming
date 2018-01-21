class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (n <= 1 || m <= 1) return true;

        for (int i = 0; i < m; i++) {
            int first = matrix[0][i];
            for (int col = i+1, row = 1; col < m && row < n; col++, row++) {
                if (first != matrix[row][col]) {
                    return false;
                }
            }
        }
        for (int i = n-1; i > 0; i--) {
            int first = matrix[i][0];
            for (int col = 1, row = i+1; col < m && row < n; col++, row++) {
                if (first != matrix[row][col]) {
                    return false;
                }
            }
        }

        return true;
    }
};