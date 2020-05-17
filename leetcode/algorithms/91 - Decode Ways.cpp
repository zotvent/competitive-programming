class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0' ? 0 : 1);
        
        int tmp;
        
        for (int i = 2; i < dp.size(); i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            tmp = stoi(s.substr(i - 2, 2));
            
            if (tmp > 9 && tmp < 27) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[s.size()];
    }
};