class Solution {
public:
    bool isValid(string s) {
       stack<char> brackets;

        for (int i = 0; i < s.length(); i++) {
            if (isOpenBracket(s[i]))
                brackets.push(s[i]);
            else if (!brackets.empty() && complement(brackets.top(), s[i]))
                brackets.pop();
            else {
                brackets.push(s[i]);
                break;
            }
        }

        return brackets.empty();
    }
    
    bool isOpenBracket(char c) {
        return c == '(' || c == '{' || c == '[';
    }
    
    bool complement(char open, char close) {
        return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
    }
};