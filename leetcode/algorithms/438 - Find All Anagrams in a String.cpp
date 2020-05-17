class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        
        if (s.size() < p.size()) {
            return res;
        }
        
        vector<int> pattern(26, 0);
        vector<int> cur(26, 0);
        int offset = p.size() - 1;
        
        for (auto& c: p) {
            pattern[c - 'a']++;
        }
        for (int i = 0; i < offset; i++) {
            cur[s[i] - 'a']++;
        }
        
        for (int i = offset; i < s.size(); i++) {
            cur[s[i] - 'a']++;
            
            if (cur == pattern) {
                res.push_back(i - offset);
            }
            
            cur[s[i - offset] - 'a']--;
        }
        
        return res;
    }
};