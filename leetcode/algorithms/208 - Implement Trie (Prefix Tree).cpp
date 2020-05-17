class Trie {
private:
    struct Node {
        bool isEnd;
        vector<Node*> tail;
        
        Node() {
            tail.assign(26, NULL);
            isEnd = false;
        }
    };
    
    Node* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* head = root;
        
        for (auto& c: word) {
            if (!head->tail[c - 'a']) {
                head->tail[c - 'a'] = new Node();
            }
            head = head->tail[c - 'a'];
        }
        
        head->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* head = root;
        
        for (auto& c: word) {
            if (!head->tail[c - 'a']) {
                return false;
            }
            head = head->tail[c - 'a'];
        }
        
        return head->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* head = root;
        
        for (auto& c: prefix) {
            if (!head->tail[c - 'a']) {
                return false;
            }
            head = head->tail[c - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */