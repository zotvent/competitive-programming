class Solution {
    
    string backspace(string& s) {
        string res = "";
        
        for (auto& i: s) {
            if (i != '#') res.push_back(i);
            else if (!res.empty()) res.pop_back();
        }
        
        return res;
    }
    
public:
    bool backspaceCompare(string s, string t) {
        return backspace(s) == backspace(t);
    }
};