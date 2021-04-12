class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int left = 0, right = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') left++;
            else right++;
            
            if (left == right) res = max(res, right * 2);
            else if (right >= left) {
                left = right = 0;
            }
        }
        
        left = right = 0;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;
            
            if (left == right) res = max(res, left * 2);
            else if (left >= right) {
                left = right = 0;
            }
        }
        
        return res;
    }
};