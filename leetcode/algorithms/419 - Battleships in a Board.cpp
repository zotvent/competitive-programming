class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (valid(i, j, board))
                    res++;
        
        return res;
    }
    
    bool valid(int x, int y, vector<vector<char>>& board) {
        bool isX = board[x][y] == 'X';
        bool topIsDot = x > 0 && board[x - 1][y] == '.' || !x;
        bool leftIsDot = y > 0 && board[x][y - 1] == '.' || !y;
        return isX && topIsDot && leftIsDot;
    }
};