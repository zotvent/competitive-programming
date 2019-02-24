template<typename T>
struct Node {

    T val;
    Node *prev;
    Node *next;

    Node(T x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

template<typename T>
struct Deque {

private:

    int _size;
    Node<T> *head;
    Node<T> *tail;

public:

    Deque() {
        _size = 0;
        head = NULL;
        tail = NULL;
    }

    void push_front(T x) {
        Node<T> *node = new Node<T>(x);

        if (size() == 0) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }

        _size++;
    }

    void push_back(T x) {
        Node<T> *node = new Node<T>(x);

        if (size() == 0) {
            head = node;
            tail = node;
        }
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }

        _size++;
    }

    T pop_front() {
        T res = front();

        Node<T> *next = head->next;
        if (next) {
            next->prev = NULL;
        }
        head->next = NULL;
        free(head);
        head = next;

        _size--;

        return res;
    }

    T pop_back() {
        T res = back();
        
        Node<T> *prev = tail->prev;
        if (prev) {
            prev->next = NULL;
        }
        tail->prev = NULL;
        free(tail);
        tail = prev;

        _size--;

        return res;
    }

    T front() {
        if (size() == 0) {
            throw 1;
        }

        return head->val;
    }

    T back() {
        if (size() == 0) {
            throw 1;
        }

        return tail->val;
    }

    int size() {
        return _size;
    }

    void clear() {
        _size = 0;

        while (head) {
            Node<T> *next = head->next;
            if (next) {
                next->prev = NULL;
            }
            head->next = NULL;
            free(head);
            head = next;
        }
    }

};
