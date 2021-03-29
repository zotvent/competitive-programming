class Solution {
    
    void bfs(vector<vector<int>>& used, vector<vector<int>>& matrix, const int rows, const int cols, int flag, queue<vector<int>> q) {
        const vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<int> cur;
        int row, col;
        
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            
            for (int i = 0; i < d.size(); i++) {
                row = cur[0] + d[i][0];
                col = cur[1] + d[i][1];
                
                if (valid(row, col, rows, cols) && used[row][col] < flag && matrix[row][col] >= matrix[cur[0]][cur[1]]) {
                    q.push({row, col});
                    used[row][col] += flag;
                }
            }
        }
    }
    
    bool valid(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    
    void calc(int row, int col, vector<vector<int>>& used, vector<vector<int>>& matrix, const int rows, const int cols, int flag) {
        queue<vector<int>> q;
        
        for (int i = 0; i < cols; i++) {
            q.push({row, i});
            if (used[row][i] < flag) {
                used[row][i] += flag;
            }
        }
        for (int i = 0; i < rows; i++) {
            q.push({i, col});
            if (used[i][col] < flag) {
                used[i][col] += flag;
            }
        }
        bfs(used, matrix, rows, cols, flag, q);
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        const int rows = matrix.size();
        const int cols = (matrix.empty() ? 0 : matrix[0].size());
        vector<vector<int>> used(rows, vector<int>(cols, 0));
        
        calc(0, 0, used, matrix, rows, cols, 1);
        calc(rows - 1, cols - 1, used, matrix, rows, cols, 2);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (used[i][j] == 3) {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
};