template<typename T>
struct Node {
    
    T val;
    Node *prev;

    Node(T x) {
        val = x;
        prev = NULL;
    }

};

template<typename T>
struct Stack {

private:

    Node<T> *top;
    int _size;

public:

    Stack() {
        top = NULL;
        _size = 0;
    }

    void push(int x) {
        Node<T> *node = new Node<T>(x);

        if (size() == 0) {
            top = node;
        }
        else {
            node->prev = top;
            top = node;
        }

        _size++;
    }

    T pop() {
        T res = back();

        Node<T> *prev = top->prev;
        free(top);
        top = prev;

        _size--;

        return res;
    }

    T back() {
        if (size() == 0) {
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
            Node<T> *prev = top->prev;
            free(top);
            top = prev;
        }
    }

};
