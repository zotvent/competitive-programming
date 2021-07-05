class Solution {
    
    int index(char c) {
        if (c == 'a') return 0;
        else if (c == 'e') return 1;
        else if (c == 'i') return 2;
        else if (c == 'o') return 3;
        else return 4;
    }
    
public:
    int countVowelPermutation(int n) {
        const int mod = (int) 1e9 + 7;
        vector<int> next(5), dp(5, 1);
        
        for (int i = 1; i < n; i++) {
            next[index('a')] = dp[index('e')];
            next[index('e')] = (dp[index('a')] + dp[index('i')]) % mod;
            next[index('i')] = ((dp[index('a')] + dp[index('e')]) % mod + (dp[index('o')] + dp[index('u')]) % mod) % mod;
            next[index('o')] = (dp[index('i')] + dp[index('u')]) % mod;
            next[index('u')] = dp[index('a')];
            dp = next;
        }
        
        int res = 0;
        for (auto& i: dp) {
            res = (res + i) % mod;
        }
        return res;
    }
};