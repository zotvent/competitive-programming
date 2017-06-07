class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                end = i;
                string temp = s.substr(start, end-start);
                int k = temp.length()-1;
                for (int j = start; j < end; j++) {
                    s[j] = temp[k--];
                }
                start = end+1;
            }
        }
        if (start < s.length()) {
            end = s.length();
            string temp = s.substr(start, end-start);
            int k = temp.length()-1;
            for (int j = start; j < end; j++) {
                s[j] = temp[k--];
            }
        }
        return s;
    }
};