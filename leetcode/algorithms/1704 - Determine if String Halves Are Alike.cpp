class Solution {
    
    bool isVowel(char c) {
        string vowels = "aeiouAEIOU";
        return vowels.find(c) != string::npos;
    }
    
    int countVowels(string& s, int start, int end) {
        int res = 0;
        for (int i = start; i < end; i++) {
            if (isVowel(s[i])) {
                res++;
            }
        }
        return res;
    }
    
public:
    bool halvesAreAlike(string s) {
        const int n = s.size();
        int left = countVowels(s, 0, n / 2);
        int right = countVowels(s, n / 2, n);
        return left == right;
    }
};