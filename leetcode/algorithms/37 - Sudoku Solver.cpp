class Solution {
    
    vector<unordered_set<int>> rows, cols, squares;
    vector<pair<int, int>> candidates;
    
    bool backtrack(vector<vector<char>>& board) {
        if (candidates.empty()) {
            return true;
        }
        
        pair<int, int> coordinates = candidates.back();
        int row = coordinates.first;
        int col = coordinates.second;
        
        candidates.pop_back();
        
        for (int i = 1; i <= 9; i++) {
            if (valid(row, col, i)) {
                placeCandidate(row, col, i, board);
                
                if (backtrack(board)) {
                    return true;
                }
                
                removeCandidate(row, col, i, board);
            }
        }
        
        candidates.push_back(coordinates);
        
        return false;
    }
    
    bool valid(int row, int col, int value) {
        int inRow = rows[row].count(value);
        int inCol = cols[col].count(value);
        int inSquare = squares[(row / 3) * 3 + col / 3].count(value);
        int sum = inRow + inCol + inSquare;
        
        return sum == 0;
    }
    
    void placeCandidate(int row, int col, int value, vector<vector<char>>& board) {
        rows[row].insert(value);
        cols[col].insert(value);
        squares[(row / 3) * 3 + col / 3].insert(value);
        board[row][col] = value + '0';
    }
    
    void removeCandidate(int row, int col, int value, vector<vector<char>>& board) {
        rows[row].erase(value);
        cols[col].erase(value);
        squares[(row / 3) * 3 + col / 3].erase(value);
        board[row][col] = '.';
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(9);
        cols.resize(9);
        squares.resize(9);
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    rows[i].insert(board[i][j] - '0');
                    cols[j].insert(board[i][j] - '0');
                    squares[(i/3) * 3 + j / 3].insert(board[i][j] - '0');
                }
                else {
                    candidates.push_back({i, j});
                }
            }
        }
        
        backtrack(board);
    }
};