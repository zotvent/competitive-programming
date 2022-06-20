class Solution {

    void calc(string& s, int l, int r, int& left, int& right) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        
        l++;
        r--;
        
        if (r - l > right - left) {
            left = l;
            right = r;
        }
    }

public:
    string longestPalindrome(string s) {
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < s.size(); i++) {
            calc(s, i - 1, i, left, right); // odd
            calc(s, i, i, left, right); // even
        }
        
        return s.substr(left, right - left + 1);
    }
};