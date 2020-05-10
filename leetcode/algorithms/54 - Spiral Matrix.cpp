class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int n = matrix.size();
        int m = (matrix.empty() ? 0 : matrix[0].size());
        
        vector<vector<int>> used(n, vector<int>(m, 0));
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int r = 0;
        int c = 0;
        int di = 0;
        int x, y;
        
        for (int i = 0; i < n * m; i++) {
            res.push_back(matrix[r][c]);
            used[r][c] = 1;
            
            x = r + dx[di];
            y = c + dy[di];
            
            if (x >= 0 && x < n && y >= 0 && y < m && !used[x][y]) {
                r = x;
                c = y;
            }
            else {
                di = (di + 1) % 4;
                r += dx[di];
                c += dy[di];
            }
        }
        
        return res;
    }
};