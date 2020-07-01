class CustomStack {
    
    vector<int> stack, inc;
    int size;
    
public:
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < size) {
            stack.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        if (stack.empty()) {
            return -1;
        }
        
        int index = stack.size() - 1;
        
        if (index > 0) {
            inc[index - 1] += inc[index];
        }
        
        int res = stack[index] + inc[index];
        stack.pop_back();
        inc.pop_back();
        
        return res;
    }
    
    void increment(int k, int val) {
        int index = min(k, (int) stack.size()) - 1;
        if (index >= 0) {
            inc[index] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */