class Solution {
public:
    string decodeString(string s) {
        string res = "", num;
        stack<int> nums;
        stack<string> curs;
        int n;
        
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                while (isdigit(s[i])) {
                    num.push_back(s[i++]);
                }
                nums.push(stoi(num));
                num.clear();
                i--;
            }
            else if (s[i] == '[') {
                curs.push(res);
                res.clear();
            }
            else if (s[i] == ']') {
                n = nums.top();
                nums.pop();
                
                string next;
                for (int j = 0; j < n; j++) {
                    next = next + res;
                }
                
                res = curs.top() + next;
                curs.pop();
            }
            else {
                res.push_back(s[i]);
            }
        }
        
        return res;
    }
};