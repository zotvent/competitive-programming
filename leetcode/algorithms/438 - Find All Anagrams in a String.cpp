class Solution {
    
    vector<int> frequency(string s) {
        vector<int> res(26, 0);
        for (auto& i: s) {
            res[i - 'a']++;
        }
        return res;
    }
    
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        const int S = s.size(), P = p.size();
        vector<int> pattern = frequency(p);
        vector<int> mapping = frequency(s.substr(0, min(S, P - 1)));
        
        for (int i = P - 1; i < S; i++) {
            mapping[s[i] - 'a']++;
            if (pattern == mapping) {
                res.push_back(i - P + 1);
            }
            mapping[s[i - P + 1] - 'a']--;
        }
        
        return res;
    }
};