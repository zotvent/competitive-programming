class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        const int n = costs.size();
        vector<int> prev = costs[0], next(3, 0);

        for (int i = 1; i < n; i++) {
            next[0] = min(prev[1], prev[2]) + costs[i][0];
            next[1] = min(prev[0], prev[2]) + costs[i][1];
            next[2] = min(prev[0], prev[1]) + costs[i][2];
            prev = next;
        }
        
        return min(prev[0], min(prev[1], prev[2]));
    }
};