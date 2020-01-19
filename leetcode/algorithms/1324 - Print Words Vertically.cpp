class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> res;
        
        int wordIndex = 0;
        int charIndex = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                wordIndex++;
                charIndex = 0;
            }
            else {
                if (res.size() <= charIndex) {
                    res.push_back("");
                }
                
                while (res[charIndex].size() < wordIndex) {
                    res[charIndex].push_back(' ');
                }
                res[charIndex].push_back(s[i]);
                
                charIndex++;
            }
        }
        
        return res;
    }
};