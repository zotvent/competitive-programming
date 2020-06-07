class TwoSum {
private:
    unordered_map<int, int> m;
    
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        int first;
        int second;
        
        for (auto it = m.begin(); it != m.end(); it++) {
            first = it->first;
            second = value - first;
            
            if (m.count(second) > 0 && (first != second || it->second > 1)) {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */