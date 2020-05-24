class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node* prev;
        
        Node(int val) {
            this->val = val;
            next = prev = NULL;
        };
    };
    
    Node* head;
    Node* tail;
    int size;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size) return -1;
        
        Node* cur = head;
        int cnt = 0;
        
        while (cnt < index) {
            cur = cur->next;
            cnt++;
        }
        
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* n = new Node(val);
        
        if (size == 0) {
            head = tail = n;
        }
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
        
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* n = new Node(val);
        
        if (size == 0) {
            head = tail = n;
        }
        else {
            tail->next = n;
            n->prev = tail;
            tail = tail->next;
        }
        
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        else if (index == size) {
            addAtTail(val);
        }
        else if (index == 0) {
            addAtHead(val);
        }
        else {
            Node* cur = head;
            int cnt = 0;
            
            while (cnt + 1 < index) {
                cur = cur->next;
                cnt++;
            }
            
            Node* n = new Node(val);
            n->next = cur->next;
            cur->next->prev = n;
            n->prev = cur;
            cur->next = n;
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size) return;
        else if (index == 0) {
            Node* cur = head;
            head = head->next;
            
            if (head) {
                head->prev = NULL;
            }
            cur->next = NULL;
            cur = NULL;
            
            size--;
        }
        else if (index == size - 1) {
            Node* cur = tail;
            tail = tail->prev;
            cur->prev = NULL;
            cur = NULL;
            if (tail) {
                tail->next = NULL;
            }
            size--;
        }
        else {
            Node* cur = head;
            int cnt = 0;
            
            while (cnt + 1 < index) {
                cur = cur->next;
                cnt++;
            }
            
            Node* tmp = cur->next;
            
            cur->next = tmp->next;
            
            tmp->next = NULL;
            tmp->prev = NULL;
            tmp = NULL;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */