class Solution {
    
    int calculateMask(string& s) {
        int mask = 0;
        for (auto& c: s) {
            mask |= 1 << (c - 'a');
        }
        return mask;
    }
    
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        const int n = words.size();
        unordered_map<int, int> m;
        int mask;
        
        for (int i = 0; i < n; i++) {
            mask = calculateMask(words[i]);
            if (m.count(mask) == 0) m[mask] = words[i].size();
            else m[mask] = max(m[mask], (int) words[i].size());
        }
        
        for (auto i = m.begin(); i != m.end(); i++) {
            for (auto j = m.begin(); j != m.end(); j++) {
                if ((i->first & j->first) == 0) {
                    res = max(res, i->second * j->second);
                }
            }
        }
        
        return res;
    }
};