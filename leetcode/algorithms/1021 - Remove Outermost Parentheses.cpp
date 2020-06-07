class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        int open = 0;
        
        for (auto& c: S) {
            if (c == '(' && open++ > 0) res.push_back(c);
            if (c == ')' && open-- > 1) res.push_back(c);
        }
        
        return res;
    }
};