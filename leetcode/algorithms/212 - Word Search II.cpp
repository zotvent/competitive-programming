class Solution {
    
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        string word;
        bool isWord;
        
        TrieNode() {
            word = "";
            isWord = false;
        }
    };
    
    const vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        TrieNode* cur;
        
        for (auto& word: words) {
            cur = root;
            
            for (auto& c: word) {
                if (!cur->next[c]) {
                    cur->next[c] = new TrieNode();
                }
                cur = cur->next[c];
            }
            
            cur->isWord = true;
            cur->word = word;
        }
        
        return root;
    }
    
    void find(vector<vector<char>>& board, int row, int col, TrieNode* parent, vector<string>& res) {
        char originalLetter = board[row][col];
        TrieNode* cur = parent->next[originalLetter];
        
        int rows = board.size();
        int cols = (board.empty()) ? 0 : board[0].size();
        
        if (cur->isWord) {
            res.push_back(cur->word);
            cur->isWord = false;
            cur->word.clear();
        }
        
        board[row][col] = '.';
        
        int x, y;
        
        for (int i = 0; i < d.size(); i++) {
            x = row + d[i][0];
            y = col + d[i][1];
            
            if (valid(rows, cols, x, y) && cur->next[board[x][y]]) {
                find(board, x, y, cur, res);
            }
        }
        
        board[row][col] = originalLetter;
    }
    
    bool valid(int rows, int cols, int row, int col) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        
        TrieNode* root = buildTrie(words);
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (root->next[board[i][j]]) {
                    find(board, i, j, root, res);
                }
            }
        }
        
        return res;
    }
};