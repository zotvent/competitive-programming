class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        
        int dx;
        int dy;
        
        for (int i = 1; i < points.size(); i++) {
            dx = abs(points[i][0] - points[i - 1][0]);
            dy = abs(points[i][1] - points[i - 1][1]);
            res += max(dx, dy);
        }
        
        return res;
    }
};