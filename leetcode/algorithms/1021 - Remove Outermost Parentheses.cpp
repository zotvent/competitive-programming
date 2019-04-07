class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int brackets = 0;
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                ++brackets;
                if (brackets > 1) res.push_back(S[i]);
            }
            else {
                --brackets;
                if (brackets > 0) res.push_back(S[i]);
            }
        }
        
        return res;
    }
};