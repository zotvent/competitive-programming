class LRUCache {
    
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> nums; // (key, value)
    list<pair<int, int>>::iterator it;
    int size;
    
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (m.count(key) > 0) {
            it = m[key];
            int value = (*it).second;
            
            nums.erase(it);
            nums.push_back({key, value});
            it = nums.end();
            it--;
            m[key] = it;
            
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.count(key) > 0) {
            it = m[key];
            nums.erase(it);
        }
        else if (m.size() == size) {
            it = nums.begin();
            m.erase((*it).first);
            nums.pop_front();
        }
        
        nums.push_back({key, value});
        it = nums.end();
        it--;
        m[key] = it;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */