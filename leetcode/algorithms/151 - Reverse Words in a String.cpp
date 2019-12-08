class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        int start = 0;
        int cnt = 0;
        int sz = s.size();
        
        while (true) {
            while (i < sz && s[i] == ' ') i++; // trim spaces
            if (i == sz) break;
            if (cnt) s[j++] = ' '; // add space between words
            start = j;
            while (i < sz && s[i] != ' ') s[j++] = s[i++];
            reverseWord(s, start, j - 1); // reverse each word separately
            cnt++;
        }
        
        s.resize(j); // remove redundant characters
        reverseWord(s, 0, s.size() - 1); // reverse whole answer
        
        return s;
    }
    
    void reverseWord(string& word, int l, int r) {
        while (l < r) {
            swap(word[l++], word[r--]);
        }
    }
};