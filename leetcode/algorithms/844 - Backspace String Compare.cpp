class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s = calc(S);
        stack<char> t = calc(T);
        return s == t;
    }
    
    stack<char> calc(string str) {
        stack<char> s;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '#') {
                if (!s.empty()) s.pop();
            }
            else s.push(str[i]);
        }
        return s;
    }
};