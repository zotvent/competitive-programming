class Solution {
public:
    string reverseWords(string s) {
        string res = s;
        int begin = 0;

        for (int i = 0; i < res.length(); i++)
            if (s[i] == ' ') {
                reverse(res, begin, i);
                begin = i + 1;
            }
        reverse(res, begin, res.length());

        return res;
    }

    void reverse(string& s, int from, int to) {
        for (int j = 0; j < (to - from) / 2; j++)
            swap(s[from + j], s[to - j - 1]);
    }
};