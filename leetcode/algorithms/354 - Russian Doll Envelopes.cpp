class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp;
        
        sort(envelopes.begin(), envelopes.end(), [](vector<int> l, vector<int> r) {
            return l[0] < r[0] || (l[0] == r[0] && l[1] > r[1]);
        });
        
        for (auto e: envelopes) {
            auto iter = lower_bound(dp.begin(), dp.end(), e[1]);
            if (iter == dp.end()) {
                dp.push_back(e[1]);
            }
            else if (e[1] < *iter) {
                *iter = e[1];
            }
        }
        
        return dp.size();
    }
};