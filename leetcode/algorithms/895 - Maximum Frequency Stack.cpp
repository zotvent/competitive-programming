class FreqStack {
    unordered_map<int, int> freq;
    map<int, stack<int>> m;
    int maxFreq;
    
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        int f = ++freq[x];
        if (f > maxFreq) {
            maxFreq = f;
        }
        m[f].push(x);
    }
    
    int pop() {
        int res = m[maxFreq].top();
        m[maxFreq].pop();
        freq[res]--;
        if (m[maxFreq].empty()) {
            maxFreq--;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */