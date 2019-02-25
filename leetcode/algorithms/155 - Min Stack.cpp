class MinStack {
    
    stack<int> st, min;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        
        if (min.empty()) {
            min.push(x);    
        }
        else if (!min.empty() && min.top() >= x) {
            min.push(x);
        }
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        
        if (top == min.top()) {
            min.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */