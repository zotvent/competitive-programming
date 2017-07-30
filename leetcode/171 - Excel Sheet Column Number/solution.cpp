class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int multi = 1;
        for (int i = s.length()-1; i >= 0; i--) {
            res += ((int) (s[i] - 'A') + 1) * multi;
            multi *= 26;
        }
        return res;
    }
};