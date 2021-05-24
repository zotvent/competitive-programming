class Solution {
    
    bool match(string& word, string& pattern) {
        vector<int> m(26, -1), rev(26, -1);
        int key, value;
        
        for (int i = 0; i < word.size(); i++) {
            key = pattern[i] - 'a';
            value = word[i] - 'a';
            
            if (m[key] == -1 && rev[value] == -1) {
                m[key] = value;
                rev[value] = key;
            }
            else if (m[key] != value || rev[value] != key) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        for (auto& i: words) {
            if (match(i, pattern)) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};