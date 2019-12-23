class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int res = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int inf = (int) 1e9;
        
        int visited[n][m][k + 1];
        memset(visited, 0, sizeof(int) * n * m * (k + 1));
        queue< vector<int> > q;

        q.push({0, 0, 0});
        visited[0][0][0] = 1;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int x, y, obs, sz;
        vector<int> v;
        
        while (!q.empty()) {
            sz = q.size();
            
            for (int o = 0; o < sz; o++) {
                v = q.front();
                q.pop();
                
                if (v[0] == n - 1 && v[1] == m - 1) {
                    return res;
                }
                
                for (int i = 0; i < 4; i++) {
                    x = v[0] + dx[i];
                    y = v[1] + dy[i];
                    obs = v[2];

                    if (isValid(x, y, n, m)) {
                        // meet obstacle
                        if (grid[x][y]) obs++;
                        
                        if (obs <= k && !visited[x][y][obs]) {
                            visited[x][y][obs] = 1;
                            q.push({x, y, obs});
                        }
                    }
                }
            }
            
            res++;
        }
        
        return -1;
    }
    
    bool isValid(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
};