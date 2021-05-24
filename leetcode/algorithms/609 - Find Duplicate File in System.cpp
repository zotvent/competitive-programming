class Solution {
    
    void process(string& s, unordered_map<string, vector<string>>& m) {
        string path = "", file = "", content = "";
        int head = 0;
        
        while (head < s.size() && s[head] != ' ') {
            path.push_back(s[head++]);
        }
        head++;
        
        bool foundFileName = false;
        
        while (head < s.size()) {
            if (s[head] == ')') {
                m[content].push_back(path + "/" + file);
                file.clear();
                content.clear();
                foundFileName = false;
                head++;
            }
            else if (s[head] == '(') foundFileName = true;
            else if (!foundFileName) file.push_back(s[head]);
            else content.push_back(s[head]);
            
            head++;
        }
    }
    
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m; // content -> paths
        
        for (auto& i: paths) {
            process(i, m);
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second.size() > 1) {
                res.push_back(it->second);
            }
        }
        
        return res;
    }
};