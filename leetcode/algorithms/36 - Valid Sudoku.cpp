class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> rows(9);
        vector<unordered_map<char, int>> cols(9);
        vector<unordered_map<char, int>> boxes(9);
        
        char c;
        int box;
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                c = board[row][col];
                
                if (c != '.') {
                    box = (row / 3) * 3 + col / 3;
                    
                    rows[row][c]++;
                    cols[col][c]++;
                    boxes[box][c]++;
                    
                    if (rows[row][c] > 1 || cols[col][c] > 1 || boxes[box][c] > 1) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};