class LRUCache {

    int size, time;
    unordered_map<int, pair<int, int>> byKey; // key -> (value, time)
    map<int, int> byTime; // time -> key
    
public:
    LRUCache(int capacity) {
        size = capacity;
        time = 0;
    }
    
    int get(int key) {
        if (byKey.count(key) > 0) {
            int oldTime = byKey[key].second;
            byTime.erase(oldTime);
            byTime[time] = key;
            byKey[key].second = time++;
            return byKey[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (byKey.count(key) > 0) {
            int oldTime = byKey[key].second;
            byTime.erase(oldTime);
        }
        else if (byKey.size() == size) {
            int oldKey = byTime.begin()->second;
            byTime.erase(byTime.begin());
            byKey.erase(oldKey);
        }
        
        byTime[time] = key;
        byKey[key] = {value, time};
        time++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */