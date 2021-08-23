class Solution {
    
    const int size = 9;
    vector<unordered_set<int>> rows, cols, boxes;
    
    int boxIndex(int row, int col) {
        return (row / 3) * 3 + col / 3;
    }
    
    void add(int row, int col, int digit) {
        rows[row].insert(digit);
        cols[col].insert(digit);
        boxes[boxIndex(row, col)].insert(digit);
    }
    
    void remove(int row, int col, int digit, vector<unordered_set<int>>& rows, vector<unordered_set<int>>& cols, vector<unordered_set<int>>& boxes) {
        rows[row].erase(digit);
        cols[col].erase(digit);
        boxes[boxIndex(row, col)].erase(digit);
    }
    
    bool valid(int row, int col, int digit) {
        return rows[row].count(digit) == 0 && cols[col].count(digit) == 0 && boxes[boxIndex(row, col)].count(digit) == 0;
    }
    
    bool next(vector<vector<char>>& board, int row, int col) {
        if (row == size - 1 && col == size - 1) {
            return true;
        }
        
        if (col < size - 1) return backtrack(board, row, col + 1);
        else return backtrack(board, row + 1, 0);
    }
    
    bool backtrack(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] != '.') {
            return next(board, row, col);
        }
        
        for (int i = 1; i <= size; i++) {
            if (valid(row, col, i)) {
                add(row, col, i);
                board[row][col] = i + '0';
                if (next(board, row, col)) return true;
                board[row][col] = '.';
                remove(row, col, i, rows, cols, boxes);
            }
        }
        
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(size);
        cols.resize(size);
        boxes.resize(size);
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] != '.') {
                    add(i, j, board[i][j] - '0');
                }
            }
        }
        
        backtrack(board, 0, 0);
    }
};