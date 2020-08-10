class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size() - 1;
        int m;
        
        while (l < r) {
            m = l + (r - l) / 2;
            
            if (letters[m] <= target) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        
        if (letters[l] <= target) {
            l = 0;
        }
        
        return letters[l];
    }
};