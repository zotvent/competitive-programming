class TicTacToe {
    
    int size;
    vector<int> cols, rows, diagonals;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        cols.assign(n, 0);
        rows.assign(n, 0);
        diagonals.assign(2, 0); // 0 - main, 1 - reverse
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int cur = (player == 1) ? -1 : 1;
        
        cols[col] += cur;
        rows[row] += cur;
        
        if (row == col) diagonals[0] += cur;
        if (size - 1 - row == col) diagonals[1] += cur;
        
        if (abs(cols[col]) == size ||
            abs(rows[row]) == size ||
            abs(diagonals[0]) == size ||
            abs(diagonals[1]) == size) {
            return player;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */