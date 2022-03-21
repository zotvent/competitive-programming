class Solution {
    
    void backtrack(int l, int r, string& cur, vector<string>& res, unordered_map<char, char>& m) {
        if (r < l) {
            res.push_back(cur);
            return;
        }
        
        for (auto& i: m) {
            // can't start with 0
            if (l == 0 && r > l && i.first == '0') continue;
            // can't be single
            if (l == r && (i.first == '6' || i.first == '9')) continue;
            cur[l] = i.first;
            cur[r] = i.second;
            backtrack(l + 1, r - 1, cur, res, m);
        }
    }
    
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        unordered_map<char, char> m = {{'1', '1'}, {'0', '0'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        unordered_map<char, bool> canStartWith = {{'1', '1'}, {'0', '0'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        string cur;
        cur.resize(n);
        backtrack(0, n - 1, cur, res, m);
        return res;
    }
};