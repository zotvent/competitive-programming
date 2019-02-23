struct Node {
    
    int val;
    Node *next;

    Node(int x) {
        val = x;
        next = NULL;
    }

};

struct Queue {
    
private:

    int _size;
    Node *head;
    Node *tail;

public:

    Queue() {
        head = NULL;
        tail = NULL;
        _size = 0;
    }

    void push(int x) {
        Node *node = new Node(x);
        
        if (_size == 0) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }

        _size++;
    }

    int pop() {
        if (_size == 0) {
            throw 1;
        }

        int res = head->val;

        Node *next = head->next;
        free(head);
        head = next;
        _size--;

        return res;
    }

    int front() {
        if (_size == 0) {
            throw 1;
        }

        return head->val;
    }

    int size() {
        return _size;
    }

    void clear() {
        _size = 0;

        while (head) {
            Node *next = head->next;
            free(head);
            head = next;
        }
    }

};
