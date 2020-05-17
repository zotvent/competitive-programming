class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int n = matrix.size();
        int m = (matrix.empty() ? 0 : matrix[0].size());
        
        int dx[] = {-1, 1};
        int dy[] = {1, -1};
        
        int row = 0;
        int col = 0;
        int di = 0;
        
        for (int i = 0; i < n * m; i++) {            
            res.push_back(matrix[row][col]);
            
            if (di == 0 && (row == 0 || col == m - 1)) {
                di = (di + 1) % 2;
                
                if (col == m - 1) row++;
                else col++;
            }
            else if (di == 1 && (col == 0 || row == n - 1)) {
                di = (di + 1) % 2;
                
                if (row == n - 1) col++;
                else row++;
            }
            else {
                row += dx[di];
                col += dy[di];
            }
        }
        
        return res;
    }
};