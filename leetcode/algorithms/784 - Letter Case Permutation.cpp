class Solution {
    
    void backtrack(string& s, int head, vector<string>& res) {
        if (head == s.size()) {
            res.push_back(s);
            return;
        }
        
        char original = s[head];
        
        s[head] = tolower(s[head]);
        backtrack(s, head + 1, res);
        
        if (tolower(s[head]) != toupper(s[head])) {
            s[head] = toupper(s[head]);
            backtrack(s, head + 1, res);
        }
        
        s[head] = original;
    }
    
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }
};