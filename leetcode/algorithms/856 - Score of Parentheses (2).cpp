class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, balance = 0;
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                balance++;
            }
            else {
                balance--;
                
                if (i > 0 && S[i - 1] == '(') {
                    res += (1 << balance);
                }
            }
        }
        
        return res;
    }
};