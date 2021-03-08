class MyHashMap {
    int mod;
    vector<vector<pair<int, int>>> nums;
    
    int hash(int key) {
        return key / mod;
    }
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        mod = (int) 1e4;
        nums.resize(100);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        
        for (auto& i: nums[index]) {
            if (i.first == key) {
                i.second = value;
                return;
            }
        }
        
        nums[index].push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        
        for (auto& i: nums[index]) {
            if (i.first == key) {
                return i.second;
            }
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        
        for (auto& i: nums[index]) {
            if (i.first == key) {
                swap(i, nums[index].back());
                nums[index].pop_back();
                break;
            }
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