class Solution {
    
    struct Trie {
        vector<Trie*> children;
        bool isWord;
        
        Trie() {
            children.assign(26, NULL);
            isWord = false;
        }
    };
    
    Trie* buildTrie(vector<string>& words) {
        Trie* root = new Trie();
        Trie* cur;
        
        for (auto& word: words) {
            cur = root;
            for (auto& c: word) {
                if (!cur->children[c - 'a']) {
                    cur->children[c - 'a'] = new Trie();
                }
                cur = cur->children[c - 'a'];
            }
            cur->isWord = true;
        }
        
        return root;
    }
    
    void search(Trie* root, vector<string>& words, string& word) {
        if (!root) return;
        if (words.size() == 3) return;
        
        if (root->isWord) {
            words.push_back(word);
        }
        
        for (int i = 0; i < root->children.size(); i++) {
            if (root->children[i]) {
                word.push_back(i + 'a');
                search(root->children[i], words, word);
                word.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        Trie* root = buildTrie(products);
        Trie* cur = root;
        vector<string> words;
        string word = "";
        
        for (auto& c: searchWord) {
            word.push_back(c);
            if (cur) cur = cur->children[c - 'a'];
            search(cur, words, word);
            res.push_back(words);
            words.clear();
        }
        
        return res;
    }
};