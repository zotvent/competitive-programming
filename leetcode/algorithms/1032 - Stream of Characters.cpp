class StreamChecker {
    
    struct Trie {
        unordered_map<char, Trie*> next;
        bool isWord;
        
        Trie() {
            isWord = false;
        }
    };
    
    void buildTrie(vector<string>& words) {
        root = new Trie();
        Trie* cur;
        
        maxWordLength = 0;
        string reversedWord;
        
        for (auto& word: words) {
            maxWordLength = max(maxWordLength, word.size());
            reversedWord = word;
            reverse(reversedWord.begin(), reversedWord.end());
            cur = root;
            
            for (auto& c: reversedWord) {
                if (!cur->next[c]) {
                    cur->next[c] = new Trie();
                }
                cur = cur->next[c];
            }
            
            cur->isWord = true;
        }
    }
    
    Trie* root;
    deque<char> stream;
    size_t maxWordLength;
    
public:
    StreamChecker(vector<string>& words) {
        buildTrie(words);
    }
    
    bool query(char letter) {
        stream.push_front(letter);
        
        while (stream.size() > maxWordLength) {
            stream.pop_back();
        }
        
        Trie* cur = root;
        
        for (auto& c: stream) {
            if (cur->isWord) {
                return true;
            }
            
            if (!cur->next[c]) {
                return false;
            }
            
            cur = cur->next[c];
        }
        
        return cur->isWord;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */