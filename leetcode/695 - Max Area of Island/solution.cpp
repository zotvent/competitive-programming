class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int cnt = 2;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1) {
                    dfs(grid, cnt, i, j);
                    cnt++;
                }
        int area = 0;
        map<int, int> m;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] != 0)
                    m[grid[i][j]]++;
        for (auto it = m.begin(); it != m.end(); it++)
            area = max(area, it->second);
        return area;
    }
    
    void dfs(vector<vector<int>>& grid, int color, int row, int column) {
        grid[row][column] = color;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int x = row+dx[i];
            int y = column+dy[i];
            if (valid(x, y, grid)) 
                if (grid[x][y] == 1)
                    dfs(grid, color, x, y);
        }
    }
    
    bool valid(int row, int column, vector<vector<int>>& grid) {
        return row >= 0 && row < grid.size() && column >= 0 && column < grid[0].size();
    }
};