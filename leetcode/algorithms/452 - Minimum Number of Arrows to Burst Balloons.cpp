class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        
        int res = 1;
        int end = points[0][1];
        
        sort(points.begin(), points.end());
        
        for (auto& p: points) {
            if (end < p[0]) {
                res++;
                end = p[1];
            }
            else {
                end = min(end, p[1]);
            }
        }
        
        return res;
    }
};