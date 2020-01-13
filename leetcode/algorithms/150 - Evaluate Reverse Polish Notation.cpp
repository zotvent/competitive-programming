class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        int l, r;
        
        for (int i = 0; i < tokens.size(); i++) {
            if (isSign(tokens[i])) {
                r = st.top(); st.pop();
                l = st.top(); st.pop();
                
                if (tokens[i] == "+") st.push(l + r);
                else if (tokens[i] == "-") st.push(l - r);
                else if (tokens[i] == "/") st.push(l / r);
                else st.push(l * r);
            }
            else st.push(stoi(tokens[i]));
        }
        
        return st.top();
    }
    
    bool isSign(string s) {
        return s == "+" || s == "-" || s == "/" || s == "*";
    }
};