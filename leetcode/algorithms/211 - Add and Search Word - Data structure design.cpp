class WordDictionary {
    
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        bool isWord;
        
        TrieNode() {
            isWord = false;
        }
    };
    
    TrieNode* root;
    
    bool search(TrieNode* root, string& word, int index) {
        if (!root) {
            return false;
        }
        
        if (index == word.size()) {
            return root->isWord;
        }
        
        if (word[index] == '.') {
            for (auto it = root->next.begin(); it != root->next.end(); it++) {
                if (search(it->second, word, index + 1)) {
                    return true;
                }
            }
            
            return false;
        }
        else {
            return search(root->next[word[index]], word, index + 1);
        }
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        
        for (auto& c: word) {
            if (!cur->next[c]) {
                cur->next[c] = new TrieNode();
            }
            cur = cur->next[c];
        }
        
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */