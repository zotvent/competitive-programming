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
    Node* prev;
    
    Node(T x) {
        val = x;
        prev = NULL;
    }
};

template<typename T>
struct Stack {
private:
    Node<T>* head;
    int _size;
    
public:
    Stack() {
        _size = 0;
        head = NULL;
    }
    
    void push(T x) {
        Node<T>* temp = new Node<T>(x);
        if (head)
            temp->prev = head;
        head = temp;
        _size++;
        cout << "ok" << endl;
    }
    
    void pop() {
        if (head) {
            cout << head->val << endl;
            Node<T>* temp = head->prev;
            delete head;
            head = temp;
            _size--;
        }
        else
            cout << "error" << endl;
    }
    
    void back() {
        if (head)
            cout << head->val << endl;
        else
            cout << "error" << endl;
    }
    
    void size() {
        cout << _size << endl;
    }
    
    void clear() {
        while (head) {
            Node<T>* temp = head->prev;
            delete head;
            head = temp;
        }
        _size = 0;
        cout << "ok" << endl;
    }
    
};

class Solution {
    Stack<int> s;
    string command;
    
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
            if (command == "push") {
                int n;
                cin >> n;
                s.push(n);
            }
            else if (command == "pop") s.pop();
            else if (command == "back") s.back();
            else if (command == "size") s.size();
            else if (command == "clear") s.clear();
            else if (command == "exit") {
                cout << "bye" << endl;
                break;
            }
        }
    }
    
public:
    Solution() {
        s = Stack<int>();
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
