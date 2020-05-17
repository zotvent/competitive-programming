class Solution {
public:
    string reverseWords(string s) {
        int head = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' || i == n - 1) {
                reverse(s.begin() + head, s.begin() + i + (i == n - 1));
                head = i + 1;
            }
        }
        
        return s;
    }
};