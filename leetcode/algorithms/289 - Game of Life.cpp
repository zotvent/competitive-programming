class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {        
        int n = board.size();
        int m = (board.empty() ? 0 : board[0].size());
        
        int live = 0;
        
        // -1 means that cell now dead, but previously was alive
        // 2 means that cell now alive, but previously was dead
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                live = 0;
                
                for (int r = max(0, i - 1); r <= min(n - 1, i + 1); r++) {
                    for (int c = max(0, j - 1); c <= min(m - 1, j + 1); c++) {
                        if (r == i && c == j) continue;
                        live += (abs(board[r][c]) == 1);
                    }
                }
                
                if (board[i][j] == 1) {
                    if (live < 2) board[i][j] = -1;
                    else if (live == 2 || live == 3) board[i][j] = 1;
                    else board[i][j] = -1;
                }
                else if (live == 3) {
                    board[i][j] = 2;
                }
            }
        }
        
        // finalize
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == -1) board[i][j] = 0;
                else if (board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};