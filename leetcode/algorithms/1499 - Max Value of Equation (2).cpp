class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res = INT_MIN;
        deque<pair<int, int>> q;
        
        for (auto& p: points) {
            while (!q.empty() && p[0] - q.front().second > k) {
                q.pop_front();
            }
            
            if (!q.empty()) {
                res = max(res, p[0] + p[1] + q.front().first);
            }
            
            while (!q.empty() && p[1] - p[0] > q.back().first) {
                q.pop_back();
            }
            
            q.push_back({p[1] - p[0], p[0]});
        }
        
        return res;
    }
};