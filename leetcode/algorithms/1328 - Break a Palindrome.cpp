class Solution {
public:
    string breakPalindrome(string palindrome) {        
        int sz = (int) palindrome.size();
        bool found = false;
        bool odd = (sz % 2 == 1);
        
        for (int i = 0; i < sz; i++) {
            if (palindrome[i] != 'a' && (!odd || i != sz / 2)) {
                palindrome[i] = 'a';
                found = true;
                break;
            }
        }
        
        if (!found) {
            palindrome[sz - 1] = 'b';
        }
        
        return (sz < 2 ? "" : palindrome);
    }
};