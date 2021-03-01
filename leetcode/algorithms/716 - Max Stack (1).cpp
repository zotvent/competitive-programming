class MaxStack {
    
    map<int, int> indexToValue;
    map<int, set<int>> valueToIndexes;
    int cur;
    
public:
    /** initialize your data structure here. */
    MaxStack() {
        cur = 0;
    }
    
    void push(int x) {
        indexToValue[cur] = x;
        valueToIndexes[x].insert(cur++);
    }
    
    int pop() {
        auto it = indexToValue.rbegin();
        int index = it->first;
        int value = it->second;
        
        indexToValue.erase(index);
        valueToIndexes[value].erase(index);
        if (valueToIndexes[value].empty()) {
            valueToIndexes.erase(value);
        }
        
        return value;
    }
    
    int top() {
        return (indexToValue.rbegin())->second;
    }
    
    int peekMax() {
        return (valueToIndexes.rbegin())->first;
    }
    
    int popMax() {
        auto it = valueToIndexes.rbegin();
        int value = it->first;
        
        auto lastIndex = (it->second).rbegin();
        int index = *lastIndex;
        
        (it->second).erase(index);
        if ((it->second).empty()) {
            valueToIndexes.erase(value);
        }
        indexToValue.erase(index);
        
        return value;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */