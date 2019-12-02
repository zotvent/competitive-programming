class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        rec("", n, n, res);
        return res;
    }
    
    void rec(string cur, int open, int close, vector<string>& res) {
        if (open == 0 && close == 0) {
            res.push_back(cur);
            return;
        }
        
        if (open > 0) {
            rec(cur + "(", open - 1, close, res);
        }
        
        if (close > open && close > 0) {
            rec(cur + ")", open, close - 1, res);
        }
    }
};