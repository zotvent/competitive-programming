class Solution {
    
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        
        return true;
    }
    
    void backtrack(string& s, int start, vector<string>& cur, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(cur);
        }
        
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                cur.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, cur, res);
                cur.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        backtrack(s, 0, cur, res);
        return res;
    }
};