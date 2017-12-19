class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buy = (int) 1e9;
        for (int i = 0; i < prices.size(); i++) {
            res = max(res, prices[i]-buy);
            buy = min(buy, prices[i]);
        }
        return res;
    }
};