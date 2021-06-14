class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        const int rows = maze.size();
        const int cols = maze[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<vector<int>> q;
        vector<int> cur;
        int r, c, cnt;
        
        dp[start[0]][start[1]] = 0;
        q.push(start);
        
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            
            for (auto& move: moves) {
                r = cur[0] + move[0];
                c = cur[1] + move[1];
                cnt = 0;
                
                while (r >= 0 && r < rows && c >= 0 && c < cols && !maze[r][c]) {
                    r += move[0];
                    c += move[1];
                    cnt++;
                }
                
                r -= move[0];
                c -= move[1];
                
                if (dp[cur[0]][cur[1]] + cnt < dp[r][c]) {
                    dp[r][c] = dp[cur[0]][cur[1]] + cnt;
                    q.push({r, c});
                }
            }
        }
        
        return dp[destination[0]][destination[1]] == INT_MAX ? -1 : dp[destination[0]][destination[1]];
    }
};