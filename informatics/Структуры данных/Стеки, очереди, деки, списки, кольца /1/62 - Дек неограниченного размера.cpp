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

const int inf = 1e9 + 5;
const int N = 1e5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

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

class Solution {

    string cmd;
    int x;
    Deque<int> Deque;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    
    void prepare() {
    }
    
    void output() {
    }
    
    void solution() {
        while (true) {
            cin >> cmd;
            if (cmd == "push_front") {
                cin >> x;
                Deque.push_front(x);
                cout << "ok\n";
            }
            else if (cmd == "push_back") {
                cin >> x;
                Deque.push_back(x);
                cout << "ok\n";
            }
            else if (cmd == "pop_front") {
                try {
                    int front = Deque.pop_front();
                    cout << front << endl;
                }
                catch (int exception) {
                    cout << "error\n";
                }
            }
            else if (cmd == "pop_back") {
                try {
                    int back = Deque.pop_back();
                    cout << back << endl;
                }
                catch (int exception) {
                    cout << "error\n";
                }
            }
            else if (cmd == "front") {
                try {
                    int front = Deque.front();
                    cout << front << endl;
                }
                catch (int exception) {
                    cout << "error\n";
                }
            }
            else if (cmd == "back") {
                try {
                    int back = Deque.back();
                    cout << back << endl;
                }
                catch (int exception) {
                    cout << "error\n";
                }
            }
            else if (cmd == "size") {
                cout << Deque.size() << endl;
            }
            else if (cmd == "clear") {
                Deque.clear();
                cout << "ok\n";
            }
            else {
                cout << "bye";
                break;
            }
        }
    }

public:
    
    Solution() {
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
