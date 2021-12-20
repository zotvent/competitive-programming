class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, mn = 10000, mx = -10000;
        
        for (auto& a : arrays) {
            res = max(res, max(a.back() - mn, mx - a.front()));
            mn = min(mn, a.front());
            mx = max(mx, a.back());
        }
        
        return res;
    }
};