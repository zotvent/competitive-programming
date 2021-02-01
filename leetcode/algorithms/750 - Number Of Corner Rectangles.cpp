class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int res = 0;
        const int rows = grid.size();
        const int cols = (grid.empty() ? 0 : grid[0].size());
        unordered_map<int, unordered_map<int, int>> m;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = j + 1; k < cols; k++) {
                    if (grid[i][j] && grid[i][k]) {
                        res += m[j][k];
                        m[j][k]++;
                    }
                }
            }
        }
        
        return res;
    }
};