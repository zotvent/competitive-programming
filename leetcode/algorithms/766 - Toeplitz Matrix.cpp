class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int, int> m;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (m.count(i - j) == 0) {
                    m[i - j] = matrix[i][j];
                }
                else if (m[i - j] != matrix[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};