class Solution {

    vector<string> toWords(string& s) {
        vector<string> res;
        string word = "";
        for (auto& i: s) {
            if (i == ' ') {
                res.push_back(word);
                word.clear();
            }
            else word.push_back(i);
        }
        if (!word.empty()) res.push_back(word);
        return res;
    }

public:
    bool wordPattern(string pattern, string s) {
        const int n = pattern.size();
        vector<string> words = toWords(s);
        unordered_map<char, string> m;
        unordered_map<string, char> rev;

        if (words.size() != n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            char key = pattern[i];
            string value = words[i];
            if (!m.count(key)) {
                if (rev.count(value)) {
                    return false;
                }
                m[key] = value;
                rev[value] = key;
            }
            else if (m[key] != value) {
                return false;
            }
        }
        
        return true;
    }
};
