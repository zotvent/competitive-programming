class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        
        string num = "";
        string letter;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '#') {
                num.push_back(s[i - 2]);
                num.push_back(s[i - 1]);
                i = i - 2;
            }
            else {
                num.push_back(s[i]);
            }
            
            letter.clear();
            letter.push_back((stoi(num) - 1 + 'a'));
            res = letter + res;
            
            num.clear();
        }
        
        return res;
    }
};