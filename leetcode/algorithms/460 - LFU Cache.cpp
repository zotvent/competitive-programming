class LFUCache {
    
    unordered_map<int, pair<int, int>> m; // key -> value, frequency
    unordered_map<int, list<int>> keys; // frequency -> keys
    unordered_map<int, list<int>::iterator> freqs; // key -> frequency's iterator
    int capacity, size, minFreq;
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        minFreq = -1;
    }
    
    int get(int key) {
        if (m.count(key) == 0) return -1;

        int oldFreq = m[key].second;
        
        keys[oldFreq].erase(freqs[key]);
        m[key].second++;
        keys[oldFreq + 1].push_front(key);
        freqs[key] = keys[oldFreq + 1].begin();
        
        if (keys[minFreq].empty()) minFreq++;
        
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        int storedValue = get(key);
        
        if (storedValue != -1) {
            m[key].first = value;
            return;
        }
        
        if (size == capacity) {
            int k = keys[minFreq].back();
            m.erase(k);
            freqs.erase(k);
            keys[minFreq].pop_back();
            size--;
        }
        
        minFreq = 1;
        m[key] = {value, minFreq};
        keys[minFreq].push_front(key);
        freqs[key] = keys[minFreq].begin();
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */