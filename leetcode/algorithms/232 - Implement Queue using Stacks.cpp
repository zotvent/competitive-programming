class MyQueue {
private:
    stack<int> stack_newest_on_top;
    stack<int> stack_oldest_on_top;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack_newest_on_top.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int oldest = peek();
        stack_oldest_on_top.pop();
        return oldest;
    }
    
    /** Get the front element. */
    int peek() {
        if (stack_oldest_on_top.empty()) {
           while (!stack_newest_on_top.empty()) {
               stack_oldest_on_top.push(stack_newest_on_top.top());
               stack_newest_on_top.pop();
           } 
        }
        return stack_oldest_on_top.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack_newest_on_top.empty() && stack_oldest_on_top.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */