class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool res = true;

        for (int i = 0; i < matrix.size() - 1; i++) {
            for (int j = 0; j < matrix[i].size() - 1; j++) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) 
                    res = false;
            }
        }

        return res;
    }
};