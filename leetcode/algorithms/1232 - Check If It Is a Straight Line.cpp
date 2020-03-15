class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool res = true;
        
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        
        double k = (double) dy / (double) dx;
        double b = coordinates[0][1] - k * coordinates[0][0];
        double y;
        
        for (int i = 2; i < coordinates.size(); i++) {
            y = k * coordinates[i][0] + b;
            
            if (y != (double) coordinates[i][1]) {
                res = false;
            }
        }
        
        return res;
    }
};