class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size();
        int cols = (maze.empty()) ? 0 : maze[0].size();
        
        vector<vector<int>> used(rows, vector<int>(cols, 0));
        
        queue<vector<int>> q;
        q.push(start);
        used[start[0]][start[1]] = 1;
        
        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        vector<int> v;
        int x, y;
        
        while (!q.empty()) {
            v = q.front();
            q.pop();
            
            if (v[0] == destination[0] && v[1] == destination[1]) {
                return true;
            }
            
            for (auto& dir: d) {
                x = v[0] + dir[0];
                y = v[1] + dir[1];
                
                while (x < rows && x >= 0 && y < cols && y >= 0 && maze[x][y] == 0) {
                    x += dir[0];
                    y += dir[1];
                }
                
                x -= dir[0];
                y -= dir[1];
                
                if (!used[x][y]) {
                    used[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        
        return false;
    }
};