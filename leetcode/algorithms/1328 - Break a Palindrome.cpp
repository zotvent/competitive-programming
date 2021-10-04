class Solution {
public:
    string breakPalindrome(string palindrome) {
        const int n = palindrome.size();
        if (n < 2) return "";
        
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        char old = palindrome[n - 1];
        palindrome[n - 1] = (((old - 'a') + 1) % 26) + 'a';
        return palindrome;
    }
};