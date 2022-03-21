class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        const int n = s.size();
        vector<int> brackets;
        int head = 0;
        
        for (int i = 0; i < n; i++) {
            if (!brackets.empty() && s[i] == ')' && s[brackets.back()] == '(') {
                brackets.pop_back();
            }
            else if (s[i] == '(' || s[i] == ')') {
                brackets.push_back(i);
            }
        }
        
        
        
        for (int i = 0; i < n; i++) {
            if (head < brackets.size() && i == brackets[head]) {
                head++;
            }
            else res.push_back(s[i]);
        }
        
        return res;
    }
};