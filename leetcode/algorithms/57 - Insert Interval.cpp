class Solution {
    
    void add(vector<vector<int>>& res, vector<int> interval) {
        while (!res.empty() && overlap(res.back(), interval)) {
            interval[0] = min(interval[0], res.back()[0]);
            interval[1] = max(interval[1], res.back()[1]);
            res.pop_back();
        }
        
        res.push_back(interval);
    }
    
    bool overlap(vector<int>& left, vector<int>& right) {
        return (left[0] <= right[0] && right[0] <= left[1]) ||
            (left[0] <= right[1] && right[1] <= left[1]);
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int head = 0;
        bool newIntervalUsed = false;
        const int n = intervals.size();
        
        while (head < n || !newIntervalUsed) {
            if (head == n) {
                add(res, newInterval);
                newIntervalUsed = true;
            }
            else if (newIntervalUsed) {
                add(res, intervals[head++]);
            }
            else if (intervals[head][0] == newInterval[0]) {
                if (intervals[head][1] <= newInterval[1]) {
                    add(res, intervals[head++]);
                }
                else {
                    add(res, newInterval);
                    newIntervalUsed = true;
                }
            }
            else if (intervals[head][0] < newInterval[0]) {
                add(res, intervals[head++]);
            }
            else {
                add(res, newInterval);
                newIntervalUsed = true;
            }
        }
        
        return res;
    }
};