class MyCircularQueue {
private:
    vector<int> val;
    int head, tail;
    int capacity;
    int size;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        val.resize(k);
        capacity = k;
        size = head = 0;
        tail = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        
        tail = (tail + 1) % capacity;
        val[tail] = value;
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        
        head = (head + 1) % capacity;
        size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return (isEmpty() ? -1 : val[head]);
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return (isEmpty() ? -1 : val[tail]);
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */