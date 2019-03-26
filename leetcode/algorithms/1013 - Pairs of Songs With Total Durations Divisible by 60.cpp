class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        vector<int> cnt(60, 0);
        
        for (auto t: time) {
            res += cnt[(60 - t % 60) % 60];
            ++cnt[t % 60];
        }
        
        return res;
    }
};