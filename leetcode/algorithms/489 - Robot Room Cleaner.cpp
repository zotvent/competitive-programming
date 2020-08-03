/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    
    const vector<vector<int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    unordered_map<int, unordered_set<int>> used;
    
    void backtrack(Robot& robot, int row, int col, int dir) {
        used[row].insert(col);
        robot.clean();
        
        int r, c, newDir;
        
        for (int i = 0; i < 4; i++) {
            newDir = (dir + i) % 4;
            r = row + d[newDir][0];
            c = col + d[newDir][1];
            
            if (valid(r, c) && robot.move()) {
                backtrack(robot, r, c, newDir);
                goBack(robot);
            }
            
            robot.turnRight();
        }
    }
    
    bool valid(int row, int col) {
        return used.count(row) == 0 || used[row].count(col) == 0;
    }
    
    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    
public:
    void cleanRoom(Robot& robot) {
        backtrack(robot, 0, 0, 0);
    }
};