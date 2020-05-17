class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        
        stack<int> brackets;
        unordered_set<int> indexesToRemove;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                brackets.push(i);
            }
            else if (s[i] == ')') {
                if (brackets.empty()) {
                    indexesToRemove.insert(i);
                }
                else {
                    brackets.pop();
                }
            }
        }
        
        while (!brackets.empty()) {
            indexesToRemove.insert(brackets.top());
            brackets.pop();
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (indexesToRemove.count(i) == 0) {
                res.push_back(s[i]);
            }
        }
        
        return res;
    }
};