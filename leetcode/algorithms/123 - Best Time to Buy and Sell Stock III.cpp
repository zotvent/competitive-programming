class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int oneBuy = INT_MAX;
        int twoBuy = INT_MAX;
        int oneBuyOneSell = 0;
        int twoBuyTwoSell = 0;
        
        for (auto& i: prices) {
            oneBuy = min(oneBuy, i);
            oneBuyOneSell = max(oneBuyOneSell, i - oneBuy);
            twoBuy = min(twoBuy, i - oneBuyOneSell);
            twoBuyTwoSell = max(twoBuyTwoSell, i - twoBuy);
        }
        
        return twoBuyTwoSell;
    }
};