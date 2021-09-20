class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        const int n = 3;
        vector<int> rows(n), cols(n);
        int diag = 0;
        int anti_diag = 0;
        int player = 1;
        
        for (vector<int> move : moves) {
            int row = move[0];
            int col = move[1];
            
            rows[row] += player;
            cols[col] += player;
            
            if (row == col) {
                diag += player;
            }
            if (row + col == n - 1) {
                anti_diag += player;
            }
            
            if (abs(rows[row]) == n || abs(cols[col]) == n || 
                abs(diag) == n || abs(anti_diag) == n) {
                return player == 1 ? "A" : "B";
            }
            
            player *= -1;
        }
            
        return moves.size() == n * n ? "Draw" : "Pending";
    }
};