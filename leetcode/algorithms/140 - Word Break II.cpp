class Solution {
    
    vector<string> rec(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& mem) {
        if (mem.count(s) > 0) {
            return mem[s];
        }
        
        vector<string> res, sub;
        
        if (s.empty()) {
            res.push_back("");
            return res;
        }
        
        for (auto& word: wordDict) {
            if (hasPrefix(word, s)) {
                sub = rec(s.substr(word.size()), wordDict, mem);
                
                for (auto& s: sub) {
                    res.push_back(word + (s.empty() ? "" : " ") + s);
                }
                
                sub.clear();
            }
        }
        
        mem[s] = res;
        
        return res;
    }
    
    bool hasPrefix(string prefix, string s) {
        if (s.size() < prefix.size()) {
            return false;
        }
        
        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != s[i]) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> mem;
        return rec(s, wordDict, mem);
    }
};