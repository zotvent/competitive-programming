class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (auto& row: matrix) {
            reverse(row.begin(), row.end());
        }
    }
};