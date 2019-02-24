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
        T res = head->val;

        Node<T> *next = head->next;
        free(head);
        head = next;

        _size--;

        return res;
    }

    bool isEmpty() {
        return _size == 0;
    }

};

class Solution {

    int x;
    string last_name;
    LinkedList<string> nine, ten, eleven;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        while (cin >> x) {
            cin >> last_name;

            if (x == 9) {
                nine.push_back(last_name);
            }
            else if (x == 10) {
                ten.push_back(last_name);
            }
            else {
                eleven.push_back(last_name);
            }
        }
    }
    
    void prepare() {
    }
    
    void output() {
        traverse(nine, 9);
        traverse(ten, 10);
        traverse(eleven, 11);
    }

    void traverse(LinkedList<string> &list, int x) {
        while (!list.isEmpty()) {
            string front = list.pop_front();
            cout << x << ' ' << front << endl;
        }
    }
    
    void solution() {
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
