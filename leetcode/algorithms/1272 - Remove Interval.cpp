class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        
        int left = toBeRemoved[0];
        int right = toBeRemoved[1];
        
        int l, r;
        
        for (int i = 0; i < intervals.size(); i++) {
            l = intervals[i][0];
            r = intervals[i][1];
            
            // no intersection
            if (right <= l || r <= left) {
                res.push_back(intervals[i]);
            }
            // remove inside interval
            else if (l == left && right < r) {
                res.push_back({right, r});
            }
            else if (l < left && right < r) {
                res.push_back({l, left});
                res.push_back({right, r});
            }
            // remove intersect interval
            else if (left < l && right < r) {
                res.push_back({right, r});
            }
            else if (r < right && l < left) {
                res.push_back({l, left});
            }
            
        }
        
        return res;
    }
};