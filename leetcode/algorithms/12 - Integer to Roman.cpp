class Solution {
public:
    string intToRoman(int num) {
        string res = "";

        vector<pair<char, int>> m = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
        };

        int i = m.size() - 1;
        int tmp;

        while (num > 0) {
            while (i > 0 && num < m[i].second) {
                i--;
            }

            tmp = num / m[i].second;

            if (tmp == 4) {
                res.push_back(m[i].first);
                res.push_back(m[i + 1].first);
                num -= tmp * m[i].second;
            }
            else if (i % 2 == 1 && m[i].second / 5 * 9 <= num) {
                res.push_back(m[i - 1].first);
                res.push_back(m[i + 1].first);
                num -= m[i].second / 5 * 9;
            }
            else {
                for (int j = 0; j < tmp; j++) {
                    res.push_back(m[i].first);
                }
                num -= tmp * m[i].second;
            }
        }

        return res;
    }
};