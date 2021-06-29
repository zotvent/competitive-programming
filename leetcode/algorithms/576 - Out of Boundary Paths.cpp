class Solution {
    const int mod = (int) 1e9 + 7;
    
    int rec(int rows, int cols, int moves, int row, int col, vector<vector<vector<int>>>& memo) {
        if (row == rows || col == cols || row < 0 || col < 0) return 1;
        if (moves == 0) return 0;
        if (memo[row][col][moves] >= 0) return memo[row][col][moves];
        memo[row][col][moves] = (
            (rec(rows, cols, moves - 1, row - 1, col, memo) + rec(rows, cols, moves - 1, row + 1, col, memo)) % mod +
            (rec(rows, cols, moves - 1, row, col - 1, memo) + rec(rows, cols, moves - 1, row, col + 1, memo)) % mod
        ) % mod;
        return memo[row][col][moves];
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return rec(m, n, maxMove, startRow, startColumn, memo);
    }
};