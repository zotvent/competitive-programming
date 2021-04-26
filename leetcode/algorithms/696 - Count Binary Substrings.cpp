class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, prev = 0, cur = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) {
                res += min(prev, cur);
                prev = cur;
                cur = 1;
            }
            else cur++;
        }

        return res + min(prev, cur);
    }
};