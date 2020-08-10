class Solution {
    
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word;
        
        TrieNode() {
            word = "";
        }
    };
    
    void build(TrieNode* root, string word) {
        for (auto& c: word) {
            if (!root->children[c]) {
                root->children[c] = new TrieNode();
            }
            root = root->children[c];
        }
        root->word = word;
    }
    
    string nextRoot(string word, TrieNode* root) {
        TrieNode* cur = root;
        
        for (auto& c: word) {
            if (!cur->word.empty() || !cur->children[c]) {
                break;
            }
            cur = cur->children[c];
        }
        
        return (cur->word.empty()) ? word : cur->word;
    }
    
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res = "";
        
        TrieNode* root = new TrieNode();
        
        for (auto& word: dict) {
            build(root, word);
        }
        
        string word = "";
        
        for (int i = 0; i <= sentence.size(); i++) {
            if (i == sentence.size() || !isalpha(sentence[i])) {
                if (!word.empty()) {
                    if (!res.empty()) {
                        res.push_back(' ');
                    }
                    res += nextRoot(word, root);
                }
                word = "";
            }
            else {
                word.push_back(sentence[i]);
            }
        }
        
        return res;
    }
};