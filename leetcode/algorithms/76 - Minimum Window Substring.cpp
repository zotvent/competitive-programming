class Solution {
    
    unordered_map<char, int> frequency(string& s) {
        unordered_map<char, int> res;
        for (auto& c: s) {
            res[c]++;
        }
        return res;
    }
    
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        vector<int> res = {-1, 0, 0}; // length, left, right
        unordered_map<char, int> T = frequency(t), window;
        int l = 0, r = 0, formed = 0, required = T.size();
        char c;
        
        while (r < s.size()) {
            c = s[r];
            window[c]++;
            
            if (T.count(c) && window[c] == T[c]) {
                formed++;
            }
            
            while (l <= r && formed == required) {
                if (res[0] == -1 || res[2] - res[1] > r - l) {
                    res[0] = r - l + 1;
                    res[1] = l;
                    res[2] = r;
                }
                
                c = s[l++];
                window[c]--;
                if (T.count(c) && T[c] > window[c]) {
                    formed--;
                }
            }
            
            r++;
        }
        
        return (res[0] == -1) ? "" : s.substr(res[1], res[0]);
    }
};