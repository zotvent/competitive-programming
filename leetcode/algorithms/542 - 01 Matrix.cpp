class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = (matrix.empty() ? 0 : matrix[0].size());
        
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        pair<int, int> top;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int x, y;
        
        while (!q.empty()) {
            top = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                x = top.first + dx[i];
                y = top.second + dy[i];
                
                if (valid(x, y, n, m)) {
                    if (res[x][y] > res[top.first][top.second] + 1) {
                        res[x][y] = res[top.first][top.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
        
        return res;
    }
    
    bool valid(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
};