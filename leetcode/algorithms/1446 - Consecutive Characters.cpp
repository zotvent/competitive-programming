class Solution {
public:
    int maxPower(string s) {
        int res = 1;
        int cur = 1;
        const int n = s.size();
        
        for (int i = 1; i <= n; i++) {
            if (i == n || s[i] != s[i - 1]) {
                res = max(res, cur);
                cur = 1;
            }
            else {
                cur++;
            }
        }
        
        return res;
    }
};