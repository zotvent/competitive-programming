class Solution {
    
    void backtrack(int row, int n, vector<vector<string>>& res, vector<string>& cur, vector<int>& cols, vector<int>& mainDiagonal, vector<int>& reverseDiagonal) {
        if (row == n) {
            res.push_back(cur);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cellIsFree(row, col, n, cols, mainDiagonal, reverseDiagonal)) {
                cur.push_back(string(n, '.'));
                cur.back()[col] = 'Q';
                
                cols[col] = 1;
                mainDiagonal[row - col + n] = 1;
                reverseDiagonal[row + col] = 1;
                
                backtrack(row + 1, n, res, cur, cols, mainDiagonal, reverseDiagonal);
                
                cur.pop_back();
                cols[col] = 0;
                mainDiagonal[row - col + n] = 0;
                reverseDiagonal[row + col] = 0;
            }
        }
    }
    
    bool cellIsFree(int row, int col, int n, vector<int>& cols, vector<int>& mainDiagonal, vector<int>& reverseDiagonal) {
        int res = cols[col] + mainDiagonal[row - col + n] + reverseDiagonal[row + col];
        return res == 0;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cur;
        vector<int> cols(n, 0), mainDiagonal(2 * n, 0), reverseDiagonal(2 * n, 0);
        backtrack(0, n, res, cur, cols, mainDiagonal, reverseDiagonal);
        return res;
    }
};