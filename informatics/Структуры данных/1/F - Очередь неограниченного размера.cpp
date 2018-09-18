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
    T value;
    Node *next;
    
    Node() : value(0), next(NULL) {}
    
    Node(T v) : value(v), next(NULL) {}
};

template<typename T>
struct Queue {
    
    Queue() : _size(0), head(NULL), tail(NULL) {}
    
    ~Queue() {
        free();
    }
    
    void push(T x) {
        Node<T> *new_node = new Node<T>(x);
        if (_size == 0)
            head = tail = new_node;
        else {
            tail->next = new_node;
            tail = new_node;
        }
        _size++;
        cout << "ok" << endl;
    }
    
    T pop() {
        if (size() == 0) throw underflow_error("error");
        
        T res = front();
        head = head->next;
        _size--;
        return res;
    }
    
    T front() {
        if (size() == 0) throw underflow_error("error");
        return head->value;
    }
    
    int size() {
        return _size;
    }
    
    void clear() {
        free();
        head = tail = NULL;
        cout << "ok" << endl;
    }
    
private:
    int _size;
    Node<T> *head;
    Node<T> *tail;
    
    void free() {
        while (_size > 0) {
            Node<T> *next = head->next;
            delete head;
            head = next;
            _size--;
        }
    }
};

class Solution {
    
    Queue<int> queue = Queue<int>();
    string command;
    int number;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        while (true) {
            cin >> command;
            if (command == "push") {
                cin >> number;
                queue.push(number);
            }
            else if (command == "pop") {
                try {
                    int res = queue.pop();
                    cout << res << endl;
                }
                catch(underflow_error e) {
                    cout << "error" << endl;
                }
            }
            else if (command == "front") {
                try {
                    int res = queue.front();
                    cout << res << endl;
                }
                catch(underflow_error e) {
                    cout << "error" << endl;
                }
            }
            else if (command == "size") {
                int size = queue.size();
                cout << size << endl;
            }
            else if (command == "clear")
                queue.clear();
            else if (command == "exit") {
                cout << "bye" << endl;
                break;
            }
        }
    }
    
    void output() {
    }
    
    void solution() {
    }
    
public:
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
