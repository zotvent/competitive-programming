struct Node {
    int val;
    Node *next;
    
    Node(int x) {
        val = x;
        next = NULL;
    }
};

class MyCircularQueue {
private:
    int capacity;
    int size;
    Node *head;
    Node *tail;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        else if (isEmpty()) {
            Node *node = new Node(value);
            head = node;
            tail = node;
        }
        else {
            Node *node = new Node(value);
            tail->next = node;
            tail = node;
        }
        
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        Node *next = head->next;
        free(head);
        head = next;
        size--;
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : head->val;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : tail->val;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return capacity == size;
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