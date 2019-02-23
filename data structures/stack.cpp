struct Node {
    
    int val;
    Node *prev;

    Node(int x) {
        val = x;
        prev = NULL;
    }
};

struct Stack {

private:

    Node *top;
    int _size;

public:

    Stack() {
        top = NULL;
        _size = 0;
    }

    void push(int x) {
        if (top) {
            Node *node = new Node(x);
            node->prev = top;
            top = node;
        }
        else {
            top = new Node(x);
        }
        _size++;
    }

    int pop() {
        if (_size == 0) {
            throw 1;
        }

        int res = top->val;

        _size--;
        Node *prev = top->prev;
        free(top);
        top = prev;

        return res;
    }

    int back() {
        if (_size == 0) {
            throw 1;
        }
        return top->val;
    }

    int size() {
        return _size;
    }

    void clear() {
        _size = 0;
        while (top) {
            Node *prev = top->prev;
            free(top);
            top = prev;
        }
    }

};
