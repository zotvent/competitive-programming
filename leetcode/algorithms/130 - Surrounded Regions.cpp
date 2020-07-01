class Solution {
    
    int rows, cols;
    vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }
        if (board[r][c] == 'X' || board[r][c] == '#') {
            return;
        }
        
        board[r][c] = '#';
        
        for (int i = 0; i < d.size(); i++) {
            dfs(board, r + d[i][0], c + d[i][1]);
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = (board.empty() ? 0 : board[0].size());
        
        if (rows == 0 || cols == 0) {
            return;
        }
        
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1);
        }
        
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[rows - 1][i] == 'O') dfs(board, rows - 1, i);
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};