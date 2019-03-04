class Solution {
public:
    int minAddToMakeValid(string S) {
        int open = 0;
        int close = 0;
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                open++;
            }
            else if (open > 0) {
                open--;
            }
            else {
                close++;
            }
        }
        
        return open + close;
    }
};