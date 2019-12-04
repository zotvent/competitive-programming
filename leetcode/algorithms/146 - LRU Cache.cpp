class LRUCache {
private:
    int capacity;
    int time;
    unordered_map<int, pair<int, int>> values;
    set<pair<int, pair<int, int>>> s;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        time = 0;
    }
    
    int get(int key) {
        if (values.count(key) > 0) {
            pair<int,int> tmp = values[key];
            
            s.erase(make_pair(tmp.second, make_pair(key, tmp.first)));
            tmp.second = time;
            s.insert(make_pair(tmp.second, make_pair(key, tmp.first)));
            values[key] = tmp;
            time++;
            
            return tmp.first;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (values.count(key) > 0) {
            pair<int,int> tmp = values[key];
            s.erase(make_pair(tmp.second, make_pair(key, tmp.first)));
            values.erase(key);
        }
        
        if (values.size() == capacity) {
            int lruKey = s.begin()->second.first;
            s.erase(s.begin());
            values.erase(lruKey);
        }
        
        s.insert(make_pair(time, make_pair(key, value)));
        values[key] = make_pair(value, time);
        time++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */