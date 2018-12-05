struct Node {
    int val;
    Node* prev;
    Node* next;
    
    Node(int x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

class MyCircularDeque {
private:
    int capacity;
    int size;
    Node* head;
    Node* tail;
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        else if (isEmpty()) {
            Node *node = new Node(value);
            head = node;
            tail = node;
            
            head->next = tail;
            tail->prev = head;
        }
        else {
            Node *node = new Node(value);
            node->next = head;
            head->prev = node;
            head = node;
        }
        
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        else if (isEmpty()) {
            Node *node = new Node(value);
            head = node;
            tail = node;
            
            head->next = tail;
            tail->prev = head;
        }
        else {
            Node *node = new Node(value);
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        
        Node *next = head->next;
        if (next) next->prev = NULL;
        free(head);
        head = next;
        
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        
        Node *prev = tail->prev;
        if (prev) prev->next = NULL;
        free(tail);
        tail = prev;
        
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1; 
        return head->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return tail->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == capacity;
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