class Solution {
    
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        vector<int> wordIndexes;
        
        TrieNode() {}
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        TrieNode* cur;
        
        for (int i = 0; i < words.size(); i++) {
            cur = root;
            
            for (auto& c: words[i]) {
                if (!cur->next[c]) {
                    cur->next[c] = new TrieNode();
                }
                cur = cur->next[c];
                cur->wordIndexes.push_back(i);
            }
        }
        
        return root;
    }
    
    void rec(TrieNode* root, vector<vector<string>>& res, vector<string>& candidate, int step, int N, vector<string>& words) {
        if (step == N) {
            res.push_back(candidate);
            return;
        }
        
        string prefix = "";
        
        for (auto& c: candidate) {
            prefix.push_back(c[step]);
        }
        
        vector<int> wordIndexes = findWordIndexes(root, prefix);
        
        for (auto& index: wordIndexes) {
            candidate.push_back(words[index]);
            rec(root, res, candidate, step + 1, N, words);
            candidate.pop_back();
        }
    }
    
    vector<int> findWordIndexes(TrieNode* root, string prefix) {
        for (auto &c: prefix) {
            if (!root->next[c]) {
                return {};
            }
            root = root->next[c];
        }
        
        return root->wordIndexes;
    }
    
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        
        TrieNode* root = buildTrie(words);
        vector<string> candidate;
        int size = words[0].size();
        
        for (auto& word: words) {
            candidate.push_back(word);
            rec(root, res, candidate, 1, size, words);
            candidate.pop_back();
        }
        
        return res;
    }
};