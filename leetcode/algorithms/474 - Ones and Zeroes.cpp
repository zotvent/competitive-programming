class Solution {
    
    vector<int> countZerosOnes(string& s) {
        vector<int> res(2, 0);
        for (int i = 0; i < s.size(); i++) {
            res[s[i] - '0']++;
        }
        return res;
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int res = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<int> count;
        
        for (auto& s: strs) {
            count = countZerosOnes(s);
            for (int zeros = m; zeros >= count[0]; zeros--) {
                for (int ones = n; ones >= count[1]; ones--) {
                    dp[zeros][ones] = max(dp[zeros][ones], dp[zeros - count[0]][ones - count[1]] + 1);
                    res = max(res, dp[zeros][ones]);
                }
            }
        }
        
        return res;
    }
};