class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        
        for (int i = 0; i < word.length(); i++) {
            if (isupper(word[i])) cnt++;
        }
        
        return cnt == word.length() || (cnt == 1 && isupper(word[0])) || cnt == 0;
    }
};