class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> g(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            g[i][i] = 1;
            int l = i-1;
            int r = i+1;
            // odd palindromes
            while (l >= 0 && r < n && s[l] == s[r]) {
                g[l--][r++] = 1;
            }
            // even palindromes
            l = i-1;
            r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                g[l--][r++] = 1;
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                res += g[i][j];
        return res;
    }
};