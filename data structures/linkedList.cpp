template<typename T>
struct Node {

    T val;
    Node *next;

    Node(T x) {
        val = x;
        next = NULL;
    }

};

template<typename T>
struct LinkedList {

private:

    int _size;
    Node<T> *head;
    Node<T> *tail;

public:
    
    LinkedList() {
        _size = 0;
        head = NULL;
        tail = NULL;
    }

    void push_back(T x) {
        Node<T> *node = new Node<T>(x);

        if (isEmpty()) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }

        _size++;
    }

    T pop_front() {
        T res = front();

        Node<T> *next = head->next;
        free(head);
        head = next;

        _size--;

        return res;
    }

    T front() {
        if (isEmpty()) {
            throw 1;
        }

        return head->val;
    }

    int size() {
        return _size;
    }

    bool isEmpty() {
        return _size == 0;
    }

};
