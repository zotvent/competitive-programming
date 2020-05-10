class Solution {
public:
    bool validPalindrome(string s) {        
        for (int i = 0, j = (int) s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                int l[] = {i, i + 1};
                int r[] = {j - 1, j};
                
                while (l[0] < r[0] && s[l[0]] == s[r[0]]) { l[0]++; r[0]--; }
                while (l[1] < r[1] && s[l[1]] == s[r[1]]) { l[1]++; r[1]--; }
                
                return l[0] >= r[0] || l[1] >= r[1];
            }
        }
        return true;
    }
};