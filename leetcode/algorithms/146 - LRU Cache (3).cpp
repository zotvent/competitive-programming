class LRUCache {
    
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> nums; // (key, value)
    int size;
    
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (m.count(key) == 0) return -1;
        int value = (*m[key]).second;
        put(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (m.count(key) > 0) {
            nums.erase(m[key]);
        }
        else if (m.size() == size) {
            m.erase(nums.back().first);
            nums.pop_back();
        }
        
        nums.push_front({key, value});
        m[key] = nums.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */