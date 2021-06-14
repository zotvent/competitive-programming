class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int preLast = 0, last = 0, save;

        for (int i = 2; i <= cost.size(); i++) {
            save = last;
            last = min(cost[i - 1] + last, cost[i - 2] + preLast);
            preLast = save;
        }
        
        return last;
    }
};