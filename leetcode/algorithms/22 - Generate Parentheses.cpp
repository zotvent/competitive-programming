class Solution {
    
    void backtrack(vector<string>& res, int open, int close, string& cur) {
        if (open == 0 && close == 0) {
            res.push_back(cur);
            return;
        }
        
        if (open > 0) {
            cur.push_back('(');
            backtrack(res, open - 1, close, cur);
            cur.pop_back();
        }
        if (open < close) {
            cur.push_back(')');
            backtrack(res, open, close - 1, cur);
            cur.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        backtrack(res, n, n, cur);
        return res;
    }
};