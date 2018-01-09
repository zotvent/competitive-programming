/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
        set<pair<int, int>> s;

        for (int i = 0; i < avails.size(); i++) {
            for (int j = 0; j < avails[i].size(); j++) {
                s.insert(make_pair(avails[i][j].start, avails[i][j].end));
            }
        }

        vector<Interval> res;
        int last = s.begin()->second;
        for (auto i = s.begin(); i != s.end(); i++) {
            if (last < i->first) {
                Interval temp = {last, i->first};
                res.push_back(temp);
            }
            if (last < i->second)
                last = i->second;
        }
        return res;
    }
};