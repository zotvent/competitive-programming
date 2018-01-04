class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length()-1;
        while (left < right) {
            if (!isVowel(s[left])) 
                left++;
            else if (!isVowel(s[right])) 
                right--;
            else 
                swap(s[left++], s[right--]);
        }
        return s;
    }
    
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'e' || c == 'u' || c == 'i' || c == 'o' || c == 'a';
    }
};