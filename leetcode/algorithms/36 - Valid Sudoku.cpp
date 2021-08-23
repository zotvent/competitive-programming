class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, int>> rows(9), cols(9), boxes(9);
        
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                if (board[r][c] != '.') {
                    int digit = board[r][c] - '0';
                    int box = (r / 3) * 3 + c / 3;
                    rows[r][digit]++;
                    cols[c][digit]++;
                    boxes[box][digit]++;
                    
                    if (rows[r][digit] > 1 || cols[c][digit] > 1 || boxes[box][digit] > 1) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};