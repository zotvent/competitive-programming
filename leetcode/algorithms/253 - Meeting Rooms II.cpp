class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0;
        int cur = 0;
        map<int, int> m;
        
        for (auto& i: intervals) {
            m[i[0]]++;
            m[i[1]]--;
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            cur += it->second;
            res = max(res, cur);
        }
        
        return res;
    }
};