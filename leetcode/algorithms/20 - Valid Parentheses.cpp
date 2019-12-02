class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c;
        
        map<char, char> comp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for (int i = 0; i < s.size(); i++) {
            c = s[i];
            
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else if (st.empty() || st.top() != comp[c]) {
                st.push(c);
                break;
            }
            else st.pop();
        }
        
        return st.empty();
    }
};