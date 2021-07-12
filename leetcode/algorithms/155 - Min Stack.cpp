class MinStack {
    stack<int> nums, mins;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        nums.push(val);
        if (mins.empty() || mins.top() >= val) {
            mins.push(val);
        }
    }
    
    void pop() {
        if (nums.top() == mins.top()) {
            mins.pop();
        }
        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */