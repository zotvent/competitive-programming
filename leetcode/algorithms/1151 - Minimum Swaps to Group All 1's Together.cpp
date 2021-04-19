class Solution {
public:
    int minSwaps(vector<int>& data) {
        int res = INT_MAX, ones = 0, window = 0;
        
        for (auto& i: data) {
            if (i == 1) ones++;
        }
        
        for (int i = 0; i < ones; i++) {
            if (data[i] == 1) window++;
        }
        
        res = ones - window;
        
        for (int i = ones; i < data.size(); i++) {
            window -= (data[i - ones] == 1);
            window += (data[i] == 1);
            res = min(res, ones - window);
        }
        
        return res;
    }
};