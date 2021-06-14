class Solution {
    
    struct Trie {
        int wordId;
        vector<Trie*> children;
        vector<int> palindromePrefixRemaining;
        
        Trie() {
            wordId = -1;
            children.resize(26);
        }
    };
    
    Trie* buildTrie(vector<string>& words) {
        Trie* root = new Trie();
        Trie* cur;
        string word;
        
        for (int i = 0; i < words.size(); i++) {
            word = words[i];
            reverse(word.begin(), word.end());
            cur = root;
            
            for (int j = 0; j < word.size(); j++) {
                if (hasPalindromeRemaining(word, j)) {
                    cur->palindromePrefixRemaining.push_back(i);
                }
                
                if (!cur->children[word[j] - 'a']) {
                    cur->children[word[j] - 'a'] = new Trie();
                }
                cur = cur->children[word[j] - 'a'];
            }
            cur->wordId = i;
        }
        
        return root;
    }
    
    bool hasPalindromeRemaining(string& s, int start) {
        int end = s.length() - 1;
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        Trie* root = buildTrie(words);
        Trie* cur;
        
        for (int i = 0; i < words.size(); i++) {
            cur = root;
            
            for (int j = 0; j < words[i].size(); j++) {
                if (cur->wordId != -1 && hasPalindromeRemaining(words[i], j)) {
                    res.push_back({i, cur->wordId});
                }
                cur = cur->children[words[i][j] - 'a'];
                if (!cur) break;
            }
            
            if (!cur) continue;
            
            if (cur->wordId != -1 && cur->wordId != i) {
                res.push_back({i, cur->wordId});
            }
            
            for (auto& index: cur->palindromePrefixRemaining) {
                res.push_back({i, index});
            }
        }
        
        return res;
    }
};