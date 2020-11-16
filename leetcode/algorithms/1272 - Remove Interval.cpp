class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        
        for (auto& i: intervals) {
            if (i[1] <= toBeRemoved[0] || i[0] >= toBeRemoved[1]) {
                res.push_back(i);
            }
            else if (i[0] < toBeRemoved[0] && toBeRemoved[1] < i[1]) {
                res.push_back({i[0], toBeRemoved[0]});
                res.push_back({toBeRemoved[1], i[1]});
            }
            else if (i[0] < toBeRemoved[0]) {
                res.push_back({i[0], toBeRemoved[0]});
            }
            else if (i[1] > toBeRemoved[1]) {
                res.push_back({toBeRemoved[1], i[1]});
            }
        }
        
        return res;
    }
};