class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        
        int side = 8;
        vector<vector<int>> g(side, vector<int>(side, 0));
        
        for (auto q: queens) {
            g[q[0]][q[1]] = 1;
        }
        
        queue<vector<int>> q;
        
        int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
        
        vector<int> v;
        int x, y;
        
        for (int i = 0; i < 8; i++) {
            x = king[0] + dx[i];
            y = king[1] + dy[i];
            
            if (valid(x, y, side)) {
                q.push({x, y, dx[i], dy[i]});
            }
        }
        
        while (!q.empty()) {
            v = q.front();
            q.pop();
            
            if (g[v[0]][v[1]] == 1) {
                res.push_back({v[0], v[1]});
                continue;
            }
            
            x = v[0] + v[2];
            y = v[1] + v[3];
            
            if (valid(x, y, side)) {
                q.push({x, y, v[2], v[3]});
            }
        }
        
        return res;
    }
    
    bool valid(int row, int col, int side) {
        return row >= 0 && col >= 0 && row < side && col < side;
    }
};