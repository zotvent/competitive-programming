class Solution {
    
    int backtrack(int row, int n, int cnt, vector<int>& rows, vector<int>& mainDiagonal, vector<int>& reverseDiagonal) {
        for (int col = 0; col < n; col++) {
            if (cellIsFree(row, col, n, rows, mainDiagonal, reverseDiagonal)) {
                rows[col] = 1;
                mainDiagonal[row - col + n] = 1;
                reverseDiagonal[row + col] = 1;
                
                if (row + 1 == n) {
                    cnt++;
                }
                else {
                    cnt = backtrack(row + 1, n, cnt, rows, mainDiagonal, reverseDiagonal);
                }
                
                rows[col] = 0;
                mainDiagonal[row - col + n] = 0;
                reverseDiagonal[row + col] = 0;
            }
        }
        
        return cnt;
    }
    
    bool cellIsFree(int row, int col, int n, vector<int>& rows, vector<int>& mainDiagonal, vector<int>& reverseDiagonal) {
        int res = rows[col] + mainDiagonal[row - col + n] + reverseDiagonal[row + col];
        return res == 0;
    }
    
public:
    int totalNQueens(int n) {
        vector<int> rows(n, 0);
        vector<int> mainDiagonal(2 * n, 0);
        vector<int> reverseDiagonal(2 * n, 0);
        return backtrack(0, n, 0, rows, mainDiagonal, reverseDiagonal);
    }
};