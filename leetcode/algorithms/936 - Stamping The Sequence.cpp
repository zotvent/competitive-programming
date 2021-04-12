class Solution {
    
    bool replaceable(string t, int shift, string s) {
        for (int i = 0; i < s.size(); i++) {
            if (t[i + shift] != '*' && t[i + shift] != s[i]) {
                return false;
            }
        }
        return true;
    }
    
    int replace(string& t, int shift, int len, int stars) {
        for (int i = 0; i < len; i++) {
            if (t[i + shift] != '*') {
                t[i + shift] = '*';
                stars++;
            }
        }
        return stars;
    }
    
public:
    vector<int> movesToStamp(string stamp, string target) {
        string s = stamp, t = target;
        vector<int> res, visited(t.size(), 0);
        int stars = 0;
        bool found;
        
        while (stars < target.size()) {
            found = false;
            
            for (int i = 0; i <= t.size() - s.size(); i++) {
                if (!visited[i] && replaceable(t, i, s)) {
                    stars = replace(t, i, s.size(), stars);
                    found = true;
                    visited[i] = 1;
                    res.push_back(i);
                    if (stars == target.size()) {
                        break;
                    }
                }
            }
            
            if (!found) {
                return {};
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};