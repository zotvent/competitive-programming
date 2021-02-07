class Solution {
    
    void handle(stack<string>& s, string& cur) {
        if (!cur.empty()) {
            if (cur == "..") {
                if (!s.empty()) s.pop();
            }
            else if (cur == ".") {}
            else {
                s.push(cur);
            }
            cur.clear();
        }
    }
    
public:
    string simplifyPath(string path) {
        stack<string> s;
        string cur = "";
        
        for (auto& i: path) {
            if (i == '/') handle(s, cur);
            else cur.push_back(i);
        }
        
        handle(s, cur);
        
        string res = "";
        stack<string> ordered;
        
        while (!s.empty()) {
            ordered.push(s.top());
            s.pop();
        }
        
        while (!ordered.empty()) {
            res.push_back('/');
            res += ordered.top();
            ordered.pop();
        }
        
        return (res.empty() ? "/" : res);
    }
};