class Solution {
public:
    string reverseWords(string s) {
        const int n = s.size();
        for (int i = 0; i < n;) {
            if (s[i] != ' ') {
                int start = i;
                while (i < n && s[i] != ' ') i++;
                reverse(s.begin() + start, s.begin() + i);
            } else i++;
        }
        return s;
    }
};
