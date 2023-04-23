class Solution {

    const vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool valid(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }

    bool backtrack(vector<vector<char>>& board, int row, int col, string& word, int head) {
        if (head == word.size() - 1) return true;
        
        const int n = board.size();
        const int m = board[0].size();
        char letter = board[row][col];
        board[row][col] = '.';
        for (auto& i: d) {
            int r = row + i[0];
            int c = col + i[1];
            if (valid(r, c, n, m) && board[r][c] == word[head + 1]) {
                if (backtrack(board, r, c, word, head + 1)) {
                    board[row][col] = letter;
                    return true;
                }
            }
        }
        board[row][col] = letter;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0] && backtrack(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
