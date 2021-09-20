class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        const int n = s.size();
        const int alphabetSize = 26;
        
        for (int i = n - 2; i >= 0; i--) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % alphabetSize;
        }
        
        for (int i = 0; i < n; i++) {
            int letter = s[i] - 'a';
            int shift = (letter + shifts[i]) % alphabetSize;
            s[i] = shift + 'a';
        }
        
        return s;
    }
};