class Solution {
    
    bool predecessor(string& pre, string& next) {
        if (next.size() != pre.size() + 1) return false;
        
        int h1 = 0, h2 = 0, skip = 0;
        
        while (h1 < pre.size()) {
            if (pre[h1] == next[h2]) {
                h1++;
                h2++;
            }
            else {
                h2++;
                skip++;
                if (skip > 1) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        const int n = words.size();
        vector<int> dp(n, 1);
        
        sort(words.begin(), words.end(), [](string& l, string& r) {
            return l.size() < r.size();
        });
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (predecessor(words[i], words[j])) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        
        int res = 0;
        for (auto& i: dp) {
            res = max(res, i);
        }
        return res;
    }
};