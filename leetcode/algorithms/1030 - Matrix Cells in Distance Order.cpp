class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        
        vector<vector<int>> used(R, vector<int>(C, 0));
        queue<pair<int, int>> to_visit;
        used[r0][c0] = 1;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        res.push_back({r0, c0});
        to_visit.push({r0, c0});
        
        while (!to_visit.empty()) {
            pair<int, int> v = to_visit.front();
            to_visit.pop();
            
            for (int i = 0; i < 4; i++) {
                int x = v.first + dx[i];
                int y = v.second + dy[i];
                
                if (valid(x, y, R, C) && !used[x][y]) {
                    used[x][y] = 1;
                    to_visit.push({x, y});
                    res.push_back({x, y});
                }
            }
        }
        
        return res;
    }
    
    bool valid(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
};