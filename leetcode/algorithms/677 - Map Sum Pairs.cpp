class MapSum {
    
    struct Node {
        unordered_map<char, Node*> children;
        int val;
        
        Node() {
            val = 0;
        }
    };
    
    Node* root;
    unordered_map<string, int> score;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        int delta = val - score[key];
        score[key] = val;
        
        Node* cur = root;
        
        for (auto& c: key) {
            if (!cur->children[c]) {
                cur->children[c] = new Node();
            }
            cur->val += delta;
            cur = cur->children[c];
        }
        cur->val += delta;
    }
    
    int sum(string prefix) {
        Node* cur = root;
        
        for (auto& c: prefix) {
            if (!cur->children[c]) {
                return 0;
            }
            cur = cur->children[c];
        }
        
        return cur->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */