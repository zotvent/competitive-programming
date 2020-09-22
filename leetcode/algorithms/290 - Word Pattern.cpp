class Solution {
    
    vector<string> split(string& str) {
        vector<string> words;

        string word = "";
        const int n = str.size();
        
        for (int i = 0; i <= n; i++) {
            if (i == n || !isalpha(str[i])) {
                if (!word.empty()) {
                    words.push_back(word);
                }
                word.clear();
            }
            else {
                word.push_back(str[i]);
            }
        }
        
        return words;
    }
    
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> charToIndex;
        unordered_map<string, int> wordToIndex;
        vector<string> words = split(str);
        
        if (words.size() != pattern.size()) {
            return false;
        }
        
        const int n = words.size();
        char c;
        string w;
        
        for (int i = 0; i < n; i++) {
            c = pattern[i];
            w = words[i];
            
            if (charToIndex.count(c) == 0) {
                charToIndex[c] = i;
            }
            
            if (wordToIndex.count(w) == 0) {
                wordToIndex[w] = i;
            }
            
            if (charToIndex[c] != wordToIndex[w]) {
                return false;
            }
        }
        
        return true;
    }
};