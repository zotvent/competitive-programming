class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        const int n = costs.size();
        const int k = costs[0].size();
        
        for (int i = 1; i < n; i++) {
            vector<int> minColors(2, -1); // min, second min
            
            // find 2 mins from the previous step
            for (int j = 0; j < k; j++) {
                if (minColors[0] == -1 || costs[i - 1][minColors[0]] > costs[i - 1][j]) {
                    minColors[1] = minColors[0];
                    minColors[0] = j;
                }
                else if (minColors[1] == -1 || costs[i - 1][minColors[1]] > costs[i - 1][j]) {
                    minColors[1] = j;
                }
            }
            
            for (int j = 0; j < k; j++) {
                if (j == minColors[0]) costs[i][j] += costs[i - 1][minColors[1]];
                else costs[i][j] += costs[i - 1][minColors[0]];
            }
        }
        
        int res = INT_MAX;
        for (int i = 0; i < k; i++) {
            res = min(res, costs[n - 1][i]);
        }
        return res;
    }
};