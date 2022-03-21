class FreqStack {
    unordered_map<int, stack<int>> byFreq;
    unordered_map<int, int> m;
    int maxFreq;
    
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        int freq = ++m[val];
        byFreq[freq].push(val);
        maxFreq = max(maxFreq, freq);
    }
    
    int pop() {
        int value = byFreq[maxFreq].top();
        
        byFreq[maxFreq].pop();
        m[value]--;
        
        if (m[value] == 0) m.erase(value);
        if (byFreq[maxFreq].empty()) {
            byFreq.erase(maxFreq--);
        }

        return value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */