class Solution {
    
    void backtrack(string& digits, unordered_map<char, string>& m, vector<string>& res, int index, string cur) {
        if (index == digits.size()) {
            if (!cur.empty()) {
                res.push_back(cur);
            }
            return;
        }
        
        for (auto& c: m[digits[index]]) {
            cur.push_back(c);
            backtrack(digits, m, res, index + 1, cur);
            cur.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        
        backtrack(digits, m, res, 0, "");
        
        return res;
    }
};