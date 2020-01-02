class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int inf = INT_MAX;
        int n = rooms.size();
        int m = (rooms.empty() ? 0 : rooms[0].size());
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }
        
        pair<int, int> v;
        int sz, x, y;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            sz = q.size();
            
            for (int o = 0; o < sz; o++) {
                v = q.front();
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    x = v.first + dx[i];
                    y = v.second + dy[i];
                    
                    if (valid(x, y, n, m) &&
                        rooms[x][y] != -1 &&
                        rooms[x][y] > rooms[v.first][v.second] + 1) {
                        
                        rooms[x][y] = rooms[v.first][v.second] + 1;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
    }
    
    bool valid(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
};