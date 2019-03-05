class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters[letters.size() - 1]) {
            return letters[0];
        }
        
        char res = 'z';
        
        int l = 0;
        int r = letters.size() - 1;
        
        while (l <= r) {
            int m = (l + r) / 2;
            char c = letters[m];
            
            if (c <= target) {
                l = m + 1;
            }
            else {
                res = min(res, c);
                r = m - 1;
            }
        }
        
        return res;
    }
};