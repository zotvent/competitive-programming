class Solution {
public:
    string decodeString(string s) {
        string res = "";
        
        int n;
        string temp;
        stack<int> countStack;
        stack<string> resStack;
        
        int i = 0;
        
        while (i < s.size()) {
            if (isdigit(s[i])) {
                n = 0;
                while (isdigit(s[i])) {
                    n = n * 10 + (s[i] - '0');
                    i++;
                }
                countStack.push(n);
            }
            else if (s[i] == '[') {
                resStack.push(res);
                res.clear();
                i++;
            }
            else if (s[i] == ']') {
                if (resStack.empty()) temp = "";
                else {
                    temp = resStack.top();
                    resStack.pop();
                }
                
                for (int i = 0; i < countStack.top(); i++) {
                    temp += res;
                }
                countStack.pop();
                
                res = temp;
                temp.clear();
                i++;
            }
            else res.push_back(s[i++]);
        }
        
        return res;
    }
};