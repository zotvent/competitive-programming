class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        const int n = s.size();
        const int m = t.size();
        
        if (abs(n - m) > 1) {
            return false;
        }
        
        int h1 = 0, h2 = 0, ops = 0;
        
        while (h1 < n && h2 < m) {
            if (s[h1] != t[h2]) {
                ops++;
                h1 += (n >= m);
                h2 += (n <= m);
            }
            else {
                h1++;
                h2++;
            }
        }
        
        ops += (h1 != n);
        ops += (h2 != m);
        
        return ops == 1;
    }
};