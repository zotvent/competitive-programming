class MyHashMap {
private:
    struct Node {
        int key;
        int val;
        Node* next;
        
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = NULL;
        }
    };
    
    vector<Node*> bucket;
    int keyRange;
    
    int hash(int key) {
        return key % keyRange;
    }
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        keyRange = 769;
        bucket.resize(keyRange);
        for (int i = 0; i < keyRange; i++) {
            bucket[i] = new Node(-1, -1);
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        Node* prev = bucket[hash(key)];
        Node* root = prev->next;
        
        while (root) {
            if (root->key == key) {
                root->val = value;
                return;
            }
            prev = root;
            root = root->next;
        }
        
        prev->next = new Node(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        Node* root = bucket[hash(key)]->next;
        
        while (root) {
            if (root->key == key) {
                return root->val;
            }
            root = root->next;
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        Node* prev = bucket[hash(key)];
        Node* root = prev->next;
        
        while (root) {
            if (root->key == key) {
                prev->next = root->next;
                root->next = NULL;
                root = NULL;
                return;
            }
            prev = root;
            root = root->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */