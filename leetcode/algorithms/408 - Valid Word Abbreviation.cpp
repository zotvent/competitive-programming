class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        const int n = word.size(), m = abbr.size();
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') return false;
                
                int num = 0;
                while (j < m && isdigit(abbr[j])) {
                    num = num * 10 + abbr[j++] - '0';
                }
                i += num;
            }
            else if (word[i++] != abbr[j++]) {
                return false;
            }
        }
        
        return i == n && j == m;
    }
};