class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        
        int space = 0;
        const int n = s.size();
        
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == ' ') {
                reverse(s.begin() + space, s.begin() + i);
                space = i + 1;
            }
        }
    }
};