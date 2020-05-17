class Solution {
private:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    
    int rows;
    int cols;
    vector<vector<char>> board;
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = (board.empty() ? 0 : board[0].size());
        this->board = board;
                
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(i, j, word, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int r, int c, string word, int head) {
        if (head >= word.size()) {
            return true;
        }
        
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[head]) {
            return false;
        }
        
        board[r][c] = '#';
        
        for (int i = 0; i < 4; i++) {
            if (dfs(r + dx[i], c + dy[i], word, head + 1)) {
                return true;
            }
        }
        
        board[r][c] = word[head];
        
        return false;
    }
};