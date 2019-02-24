class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'R') {
                    res += dfs(board, i, j, 0);
                    res += dfs(board, i, j, 1);
                    res += dfs(board, i, j, 2);
                    res += dfs(board, i, j, 3);
                }
            }
        }
        
        return res;
    }
    
    int dfs(vector<vector<char>>& board, int x, int y, int dir) {
        int res = 0;
        
        // up
        if (dir == 0) {
            for (int i = x - 1; i >= 0; i--) {
                if (board[i][y] == 'B') {
                    break;
                }
                if (board[i][y] == 'p') {
                    res++;
                    break;
                }
            }
        }
        // right
        else if (dir == 1) {
            for (int i = y + 1; i < board.size(); i++) {
                if (board[x][i] == 'B') {
                    break;
                }
                if (board[x][i] == 'p') {
                    res++;
                    break;
                }
            }
        }
        // down
        else if (dir == 2) {
            for (int i = x + 1; i < board.size(); i++) {
                if (board[i][y] == 'B') {
                    break;
                }
                if (board[i][y] == 'p') {
                    res++;
                    break;
                }
            }
        }
        // left
        else {
            for (int i = y - 1; i >= 0; i--) {
                if (board[x][i] == 'B') {
                    break;
                }
                if (board[x][i] == 'p') {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};