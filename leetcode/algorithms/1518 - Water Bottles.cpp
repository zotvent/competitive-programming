class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        int empty = 0;
        
        do {
            res += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty -= numBottles * numExchange;
        } while (numBottles > 0);
        
        return res;
    }
};