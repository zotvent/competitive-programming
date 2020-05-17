class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        int len = digits.size();
        int n = 1;
        
        for (auto d: digits) {
            if (d == '7' || d == '9') n *= 4;
            else n *= 3;
        }
        
        vector<string> res(n, digits);
        
        unordered_map<char, string> m = {
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz" },
        };
        
        vector<int> cur(len, 0);
        
        int tmp = m[digits.back()].size();
        vector<int> d(len, 1);
        
        for (int i = len - 2; i >= 0; i--) {
            d[i] = tmp;
            tmp *= (int) m[digits[i]].size();
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < len; j++) {
                res[i][j] = m[digits[j]][cur[j]];
                
                if ((i + 1) % d[j] == 0) {
                    tmp = (int) m[digits[j]].size();
                    cur[j] = (cur[j] + 1) % tmp;
                }
            }
        }
        
        return res;
    }
};