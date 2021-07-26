class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        const int n = points.size();
        int res = INT_MIN, tail = n - 1;
        set<int> seen;
        seen.insert(points[n - 1][0] + points[n - 1][1]);
        
        for (int head = n - 2; head >= 0; head--) {
            while (tail > head && points[tail][0] - points[head][0] > k) {
                seen.erase(points[tail][0] + points[tail--][1]);
            }
            
            if (!seen.empty()) {
                res = max(res, points[head][1] - points[head][0] + *(seen.rbegin()));
            }
            seen.insert(points[head][0] + points[head][1]);
        }
        
        return res;
    }
};