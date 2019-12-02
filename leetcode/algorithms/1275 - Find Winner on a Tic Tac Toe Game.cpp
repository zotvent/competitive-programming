class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        string res;
        
        vector<vector<char>> g(3, vector<char>(3, '-'));
        char c;
        
        for (int i = 0; i < moves.size(); i++) {
            if ((i + 1) % 2 == 0) c = 'O';
            else c = 'X';
            
            g[moves[i][0]][moves[i][1]] = c;
        }
        
        vector<vector<pair<int, int>>> comb = {
            {{0, 0}, {0, 1}, {0, 2}},
            {{1, 0}, {1, 1}, {1, 2}},
            {{2, 0}, {2, 1}, {2, 2}},
            {{0, 0}, {1, 0}, {2, 0}},
            {{0, 1}, {1, 1}, {2, 1}},
            {{0, 2}, {1, 2}, {2, 2}},
            {{0, 0}, {1, 1}, {2, 2}},
            {{0, 2}, {1, 1}, {2, 0}}
        };
        
        for (int i = 0; i < comb.size(); i++) {
            if (g[comb[i][0].first][comb[i][0].second] == g[comb[i][1].first][comb[i][1].second] && 
               g[comb[i][1].first][comb[i][1].second] == g[comb[i][2].first][comb[i][2].second]) {
                if (g[comb[i][0].first][comb[i][0].second] == 'O') {
                    res = "B";
                    break;
                }
                else if (g[comb[i][0].first][comb[i][0].second] == 'X') {
                    res = "A";
                    break;
                }
            }
        }
        
        if (res.empty()) {
            res = "Draw";
            
            for (int i = 0; i < g.size(); i++) {
                for (int j = 0; j < g[i].size(); j++) {
                    if (g[i][j] == '-') {
                        res = "Pending";
                    }
                }
            }
        }
        
        return res;
    }
};