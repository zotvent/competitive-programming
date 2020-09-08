class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int cost = 0;
        
        queue<pair<int, int>> last7, last30;
        
        for (auto& day: days) {
            while (!last7.empty() && last7.front().first + 7 <= day) {
                last7.pop();
            }
            while (!last30.empty() && last30.front().first + 30 <= day) {
                last30.pop();
            }
            
            last7.push({day, cost + costs[1]});
            last30.push({day, cost + costs[2]});
            
            cost = min(cost + costs[0], min(last7.front().second, last30.front().second));
        }
        
        return cost;
    }
};