class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN;
        int held = INT_MIN;
        int reset = 0;
        int preSold;
        
        for (auto& price: prices) {
            preSold = sold;
            
            sold = held + price;
            held = max(held, reset - price);
            reset = max(reset, preSold);
        }
        
        return max(sold, reset);
    }
};