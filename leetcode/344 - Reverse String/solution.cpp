class Solution {
public:
    string reverseString(string s) {
        string reverse;
        for (int i = s.length() - 1; i >= 0; i--) {
            reverse += s[i];
        }
        return reverse;
    }
};