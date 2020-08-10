class Solution {
    
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        int wordIndex;
        vector<int> palindromePrefixRemaining;
        
        TrieNode() {
            wordIndex = -1;
        }
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        TrieNode* cur;
        
        string reversedWord;
        
        for (int wordId = 0; wordId < words.size(); wordId++) {
            cur = root;
            reversedWord = words[wordId];
            reverse(reversedWord.begin(), reversedWord.end());
            
            for (int j = 0; j < reversedWord.size(); j++) {
                if (hasPalindromeRemaining(reversedWord, j)) {
                    cur->palindromePrefixRemaining.push_back(wordId);
                }
                
                if (!cur->next[reversedWord[j]]) {
                    cur->next[reversedWord[j]] = new TrieNode();
                }
                cur = cur->next[reversedWord[j]];
            }
            
            cur->wordIndex = wordId;
        }
        
        return root;
    }
    
    bool hasPalindromeRemaining(string& word, int start) {
        int head = start;
        int tail = word.size() - 1;
        
        while (head < tail) {
            if (word[head] != word[tail]) {
                return false;
            }
            
            head++;
            tail--;
        }
        
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        
        TrieNode* root = buildTrie(words);
        TrieNode* cur;
        
        for (int wordId = 0; wordId < words.size(); wordId++) {
            cur = root;
            
            for (int j = 0; j < words[wordId].size(); j++) {
                if (cur->wordIndex != -1 && hasPalindromeRemaining(words[wordId], j)) {
                    res.push_back({wordId, cur->wordIndex});
                }
                
                cur = cur->next[words[wordId][j]];
                
                if (!cur) break;
            }
            
            if (!cur) continue;
            
            if (cur->wordIndex != -1 && cur->wordIndex != wordId) {
                res.push_back({wordId, cur->wordIndex});
            }
            
            for (auto& other: cur->palindromePrefixRemaining) {
                res.push_back({wordId, other});
            }
        }
        
        return res;
    }
};