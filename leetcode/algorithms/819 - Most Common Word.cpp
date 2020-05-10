class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string res = "";
        int cnt = 0;
        
        unordered_set<string> s(banned.begin(), banned.end());
        
        string word = "";
        unordered_map<string, int> m;
        
        for (auto c: paragraph) {
            if (!isalpha(c)) {
                if (!word.empty() && s.count(word) == 0) {
                    m[word]++;
                }
                word.clear();
            }
            else {
                word.push_back(tolower(c));
            }
        }
        
        if (!word.empty() && s.count(word) == 0) {
            m[word]++;
            word.clear();
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (cnt < it->second) {
                cnt = it->second;
                res = it->first;
            }
        }
        
        return res;
    }
};