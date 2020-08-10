class AutocompleteSystem {
    
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int cnt;
        
        TrieNode() {
            cnt = 0;
        }
    };
    
    TrieNode* root;
    string sentence;
    
    void build(TrieNode* root, string sentence, int cnt) {
        for (auto& c: sentence) {
            if (!root->children[c]) {
                root->children[c] = new TrieNode();
            }
            root = root->children[c];
        }
        root->cnt += cnt;
    }
    
    void find(TrieNode* root, string& sentence, vector<pair<int, string>>& res) {
        for (auto& c: sentence) {
            if (!root->children[c]) {
                return;
            }
            root = root->children[c];
        }
        
        find(root, res, sentence);
    }
    
    void find(TrieNode* root, vector<pair<int, string>>& res, string& sentence) {
        if (!root) {
            return;
        }
        
        if (root->cnt > 0) {
            res.push_back({root->cnt, sentence});
        }
        
        for (auto it = root->children.begin(); it != root->children.end(); it++) {
            sentence.push_back(it->first);
            find(it->second, res, sentence);
            sentence.pop_back();
        }
    }
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        sentence = "";
        
        for (int i = 0; i < sentences.size(); i++) {
            build(root, sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> res;
        
        if (c == '#') {
            build(root, sentence, 1);
            sentence.clear();
            return res;
        }
        
        vector<pair<int, string>> tmp;
        
        sentence.push_back(c);
        find(root, sentence, tmp);
        
        sort(tmp.rbegin(), tmp.rend(), [](const pair<int, string>& l, const pair<int, string>& r) {
            if (l.first == r.first) {
                return l.second > r.second;
            }
            else {
                return l.first < r.first;
            }
        });
        
        for (int i = 0; i < min(3, (int) tmp.size()); i++) {
            res.push_back(tmp[i].second);
        }
        
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */