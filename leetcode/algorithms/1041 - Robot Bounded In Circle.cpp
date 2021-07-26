class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        const int dirs = 4;
        const vector<vector<int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for (auto& i: instructions) {
            if (i == 'L') dir = (dirs + dir - 1) % dirs;
            else if (i == 'R') dir = (dir + 1) % dirs;
            else {
                x += d[dir][0];
                y += d[dir][1];
            }
        }
        
        return dir != 0 || (x == 0 && y == 0);
    }
};