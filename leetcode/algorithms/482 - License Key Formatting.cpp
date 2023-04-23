class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        int group = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') continue;
            if (group == k) {
                group = 0;
                res.push_back('-');
            }
            res.push_back(toupper(s[i]));
            group++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
