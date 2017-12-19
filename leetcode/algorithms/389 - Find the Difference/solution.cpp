class Solution {
public:
    char findTheDifference(string s, string t) {
        int const n = 128;
        int ms[n], mt[n];
        for (int i = 0; i < n; i++) {
            ms[i] = 0;
            mt[i] = 0;
        }
        for (int i = 0; i < s.length(); i++)  ms[(int) s[i]]++;
        for (int i = 0; i < t.length(); i++)  mt[(int) t[i]]++;
        
        char c;
        for (int i = 0; i < n; i++) {
            if (ms[i] != mt[i]) {
                c = (char) i;
                break;
            }
        }
        return c;
    }
};