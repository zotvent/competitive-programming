class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> m;
        
        string dir;
        string fileName;
        string content;
        
        bool dirEnded;
        bool contentStarted;
        
        for (auto& p: paths) {
            dir.clear();
            fileName.clear();
            content.clear();
            
            dirEnded = false;
            contentStarted = false;
            
            for (int i = 0; i < p.size(); i++) {
                if (!dirEnded) {
                    if (p[i] == ' ') {
                        dirEnded = true;
                    }
                    else {
                        dir.push_back(p[i]);
                    }
                }
                
                if (dirEnded) {
                    if (p[i] == ' ') {
                        fileName.clear();
                        content.clear();
                    }
                    else {
                        if (p[i] == '(') {
                            contentStarted = true;
                            continue;
                        }
                        else if (p[i] == ')') {
                            contentStarted = false;
                            m[content].push_back(dir + "/" + fileName);
                            continue;
                        }
                        
                        if (contentStarted) {
                            content.push_back(p[i]);
                        }
                        else {
                            fileName.push_back(p[i]);
                        }
                    }
                }
            }
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second.size() > 1) {
                res.push_back(it->second);
            }
        }
        
        return res;
    }
};