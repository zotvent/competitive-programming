class Solution {
    
    bool isFile(string& s) {
        return s.find('.') != string::npos;
    }
    
public:
    int lengthLongestPath(string input) {
        int res = 0;
        
        vector<string> path;
        int pathSize = 0;
        string cur = "";
        int level, j;
        const int n = input.size();
        
        for (int i = 0; i < n; i++) {
            if (input[i] == '\n') {
                if (isFile(cur)) {
                    res = max(res, pathSize + (int) cur.size() + (int) path.size());
                }
                else {
                    pathSize += cur.size();
                    path.push_back(cur);
                }

                cur.clear();
                
                j = i + 1;
                level = 0;
                while (j < n && input[j] == '\t') {
                    level++;
                    j++;
                }
                
                while (path.size() > level) {
                    pathSize -= path.back().size();
                    path.pop_back();
                }
                
                i = j - 1;
            }
            else {
                cur.push_back(input[i]);
            }
        }
        
        if (isFile(cur)) {            
            res = max(res, pathSize + (int) cur.size() + (int) path.size());
        }
        
        return res;
    }
};