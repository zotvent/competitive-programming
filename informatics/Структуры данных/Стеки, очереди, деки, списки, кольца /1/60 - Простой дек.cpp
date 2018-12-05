#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstring>

using namespace std;

#define F first
#define S second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 1e2+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

template<typename T>
struct Node {
    T val;
    Node* next;
    Node* prev;
    
    Node(T x) {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

template<typename T>
struct Dequeue {
private:
    Node<T>* head;
    Node<T>* tail;
    int _size;
    
public:
    Dequeue() {
        _size = 0;
        head = NULL;
        tail = NULL;
    }
    
    void push_front(T x) {
        Node<T> *node = new Node<T>(x);

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
        cout << "ok" << endl;
    }

    void push_back(T x) {
        Node<T> *node = new Node<T>(x);

        if (isEmpty()) {
            head = node;
            tail = node;
        }
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }

        _size++;
        cout << "ok" << endl;
    }
    
    void pop_front() {
        T res = head->val;
        Node<T> *next = head->next;
        if (next) next->prev = NULL;
        head = NULL;
        head = next;

        _size--;
        cout << res << endl;
    }

    void pop_back() {
        T res = tail->val;
        Node<T> *prev = tail->prev;
        if (prev) prev->next = NULL;
        tail = NULL;
        tail = prev;

        _size--;
        cout << res << endl;
    }
    
    void front() {
        cout << head->val << endl;
    }

    void back() {
        cout << tail->val << endl;
    }
    
    void size() {
        cout << _size << endl;
    }
    
    void clear() {
        while (head) {
            Node<T> *next = head->next;
            if (next) next->prev = NULL;
            head = NULL;
            head = next;
        }
        while (tail) {
            Node<T> *prev = tail->prev;
            if (prev) prev->next = NULL;
            tail = NULL;
            tail = prev;
        }

        _size = 0;
        cout << "ok" << endl;
    }

    bool isEmpty() {
        return _size == 0;
    }
    
};

class Solution {
    Dequeue<int> deq;
    string command;
    int n;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    
    void output() {
    }
    
    void solution() {
        while (cin >> command) {
            if (command == "push_front") {
                cin >> n;
                deq.push_front(n);
            }
            else if (command == "push_back") {
                cin >> n;
                deq.push_back(n);
            }
            else if (command == "pop_front") deq.pop_front();
            else if (command == "pop_back") deq.pop_back();
            else if (command == "front") deq.front();
            else if (command == "back") deq.back();
            else if (command == "size") deq.size();
            else if (command == "clear") deq.clear();
            else if (command == "exit") {
                cout << "bye" << endl;
                break;
            }
        }
    }
    
public:
    Solution() {
        deq = Dequeue<int>();
    }
    
    void solve() {
        input();
        solution();
        output();
    }
};

int main() {
    Solution s = Solution();
    s.solve();
    return 0;
}
