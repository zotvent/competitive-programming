class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            res += dict[s[i]];
            if (i && dict[s[i-1]] < dict[s[i]])
                res -= 2*dict[s[i-1]];
        }
        return res;
    }
};