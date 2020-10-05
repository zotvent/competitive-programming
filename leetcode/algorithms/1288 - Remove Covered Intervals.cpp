class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = 0, left = -1, right = -1;
        
        sort(intervals.begin(), intervals.end());
        
        for (auto& i: intervals) {
            if (i[0] > left && i[1] > right) {
                left = i[0];
                ++res;
            }
            
            right = max(right, i[1]);
        }
        
        return res;
    }
};