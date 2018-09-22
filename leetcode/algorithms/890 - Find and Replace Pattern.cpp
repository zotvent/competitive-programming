class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> v;
        
        for (int i = 0; i < words.size(); i++) {
            bool ok = true;
            map<char, set<char>> forward, reverse;
            
            for (int j = 0; j < words[i].length(); j++) {
                char key = words[i][j];
                char value = pattern[j];
                
                forward[key].insert(value);
                reverse[value].insert(key);
            }
            
            for (auto i = forward.begin(); i != forward.end(); i++)
                if (i->second.size() > 1) ok = false;
            for (auto i = reverse.begin(); i != reverse.end(); i++)
                if (i->second.size() > 1) ok = false;
            
            if (ok) v.push_back(words[i]);
        }
        
        return v;
    }
};