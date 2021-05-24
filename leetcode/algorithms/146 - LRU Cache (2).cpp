class LRUCache {
    
    struct Node {
        Node* prev;
        Node* next;
        int key, val;
        
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            prev = next = NULL;
        }
    };
    
    int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> byKey;
    
    void insert(int key, int value) {
        Node* node = new Node(key, value);
        
        if (tail) {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        else {
            head = node;
            tail = node;
        }
        
        byKey[key] = node;
    }
    
    void remove(int key) {
        Node* node = byKey[key];
        byKey.erase(key);
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (head == node) head = head->next;
        if (tail == node) tail = tail->prev;
        node = NULL;
    }
    
public:
    LRUCache(int capacity) {
        size = capacity;
        head = tail = NULL;
    }
    
    int get(int key) {
        if (byKey.count(key) > 0) {
            Node* res = byKey[key];
            int val = res->val;
            remove(key);
            insert(key, val);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (byKey.count(key) > 0) remove(key);
        else if (byKey.size() == size) remove(head->key);
        insert(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */