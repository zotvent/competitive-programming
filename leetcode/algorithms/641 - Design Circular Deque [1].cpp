struct Node {
        
    int val;
    Node* next;
    Node* prev;

    Node(int x) {
        val = x;
        next = NULL;
        prev = NULL;
    }

};

class MyCircularDeque {
    
    int capacity;
    int _size;
    Node* head;
    Node* tail;
    
public:
    
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k;
        _size = 0;
        head = NULL;
        tail = NULL;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        
        Node* node = new Node(value);
        
        if (isEmpty()) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        
        _size++;
        
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        
        Node* node = new Node(value);
        
        if (isEmpty()) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        
        _size++;
        
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        
        Node* next = head->next;
        if (next) {
            next->prev = NULL;
        }
        head = NULL;
        head = next;
        
        _size--;
        
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        
        Node* prev = tail->prev;
        if (prev) {
            prev->next = NULL;
        }
        tail = NULL;
        tail = prev;
        
        _size--;
        
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return (isEmpty() ? -1 : head->val);
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return (isEmpty() ? -1 : tail->val);
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return _size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return _size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */