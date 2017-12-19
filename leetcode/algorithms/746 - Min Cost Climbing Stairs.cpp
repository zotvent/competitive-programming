class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int const inf = (int) 1e9;
        int n = cost.size();
        vector<int> d(n+5, inf);
        
        d[0] = 0;
        for (int i = 0; i < n; i++) {
            d[i+1] = min(d[i+1], d[i]+cost[i]);
            d[i+2] = min(d[i+2], d[i]+cost[i]);
        }
        int zero = d[n];
        
        d.assign(n+5, inf);
        d[1] = 0;
        for (int i = 1; i < n; i++) {
            d[i+1] = min(d[i+1], d[i]+cost[i]);
            d[i+2] = min(d[i+2], d[i]+cost[i]);
        }
        int first = d[n];
        
        return min(zero, first);
    }
};