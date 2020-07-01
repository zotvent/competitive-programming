class Solution {
    
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool formsWord;
        string word;
        
        TrieNode() {
            formsWord = false;
            word = "";
        }
    };
    
    TrieNode* root;
    const vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<char>> board;
    int rows, cols;
    
    void buildTrie(vector<string>& words) {
        root = new TrieNode();
        
        for (auto& word: words) {
            TrieNode* cur = root;
            
            for (auto& c: word) {
                if (cur->children.count(c) > 0) {
                    cur = cur->children[c];
                }
                else {
                    cur->children[c] = new TrieNode();
                    cur = cur->children[c];
                }
            }
            
            cur->formsWord = true;
            cur->word = word;
        }
    }
    
    void backtrack(int row, int col, TrieNode* parent, vector<string>& res) {
        char letter = board[row][col];
        TrieNode* cur = parent->children[letter];
        
        if (cur->formsWord) {
            res.push_back(cur->word);
            cur->formsWord = false;
            cur->word.clear();
        }
        
        board[row][col] = '.';
        int x, y;
        
        for (int i = 0; i < d.size(); i++) {
            x = row + d[i][0];
            y = col + d[i][1];
            
            if (valid(x, y) && cur->children.count(board[x][y]) > 0) {
                backtrack(x, y, cur, res);
            }
        }
        
        board[row][col] = letter;
    }
    
    bool valid(int r, int c) {
        return r >= 0 && c >= 0 && r < rows && c < cols;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        
        this->board = board;
        rows = board.size();
        cols = (board.empty() ? 0 : board[0].size());        
        
        buildTrie(words);
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (root->children.count(board[i][j]) > 0) {
                    backtrack(i, j, root, res);
                }
            }
        }
        
        return res;
    }
};