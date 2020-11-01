class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int end = -1;
        
        sort(intervals.begin(), intervals.end());
        
        for (auto& i: intervals) {
            if (i[0] < end) {
                return false;
            }
            end = i[1];
        }
        
        return true;
    }
};