class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        int n = costs.size();
        
        sort(costs.begin(), costs.end(), [](const vector<int> &l, const vector<int> &r) {
            return l[0] - l[1] < r[0] - r[1];
        });
        
        for (int i = 0; i < n; i++) {
            res += (i < n / 2 ? costs[i][0] : costs[i][1]);
        }
        
        return res;
    }
};