struct TrieNode {
    
    struct TrieNode *children[26];
    
    int wordsEndingHere;
    
    TrieNode() {
        wordsEndingHere = 0;
        
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
    
};

class Solution {
public:
    vector< vector<string> > suggestedProducts(vector<string>& products, string searchWord) {
        vector< vector<string> > res;

        TrieNode *root = new TrieNode();

        for (int i = 0; i < products.size(); i++) {
            insert(root, products[i]);
        }

        string key = "";
        vector<string> tmp;

        for (int i = 0; i < searchWord.size(); i++) {
            key.push_back(searchWord[i]);
            tmp.clear();
            search(root, key, tmp);
            res.push_back(tmp);
        }

        return res;
    }

    void insert(TrieNode *root, string key) {
        TrieNode *cur = root;
        int index;

        for (int i = 0; i < key.size(); i++) {
            index = key[i] - 'a';

            if (!cur->children[index]) {
                cur->children[index] = new TrieNode();
            }

            cur = cur->children[index];
        }

        cur->wordsEndingHere++;
    }

    void search(TrieNode *root, string key, vector<string>& words) {
        TrieNode* cur = root;
        int index;

        for (int i = 0; i < key.size(); i++) {
            index = key[i] - 'a';

            if (!cur->children[index]) {
                return;
            }

            cur = cur->children[index];
        }

        if (!cur) {
            return;
        }

        int left = 3 - (int) words.size();
        for (int i = 0; i < min(cur->wordsEndingHere, left); i++) {
          words.push_back(key);
        }

        string tmp;
        for (int i = 0; i < 26; i++) {
            if (cur->children[i]) {
                tmp = key;
                tmp.push_back(i + 'a');
                rec(cur->children[i], tmp, words);
            }
        }
    }

    void rec(TrieNode *root, string key, vector<string>& words) {
        if (!root || words.size() >= 3) {
            return;
        }

        int left = 3 - (int) words.size();
        for (int i = 0; i < min(root->wordsEndingHere, left); i++) {
          words.push_back(key);
        }

        string tmp;
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                tmp = key;
                tmp.push_back(i + 'a');
                rec(root->children[i], tmp, words);
            }
        }
    }
};