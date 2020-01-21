class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res, dp = arr;
        
        for (int i = 1; i < dp.size(); i++) {
            dp[i] ^= dp[i - 1];
        }
        
        int tmp;
        for (auto q: queries) {
            tmp = (q[0] > 0 ? dp[q[0] - 1] ^ dp[q[1]] : dp[q[1]]);
            res.push_back(tmp);
        }
        
        return res;
    }
};