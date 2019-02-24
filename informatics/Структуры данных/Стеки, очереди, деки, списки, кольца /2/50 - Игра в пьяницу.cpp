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
const int N = 1e6;
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

    int x, cnt;
    LinkedList<int> first, second;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        for (int i = 0; i < 5; i++) {
            cin >> x;
            first.push_back(x);
        }
        for (int i = 0; i < 5; i++) {
            cin >> x;
            second.push_back(x);
        }
    }
    
    void prepare() {
    }
    
    void output() {
        if (second.isEmpty()) {
            printf("first %d", cnt);
        }
        else if (first.isEmpty()) {
            printf("second %d", cnt);
        }
        else {
            cout << "botva";
        }
    }
    
    void solution() {
        while (!first.isEmpty() && !second.isEmpty() && cnt < N) {
            int f = first.pop_front();
            int s = second.pop_front();

            bool fIsWinner = firstIsWinner(f, s);

            if (fIsWinner) {
                first.push_back(f);
                first.push_back(s);
            }
            else {
                second.push_back(f);
                second.push_back(s);
            }

            cnt++;
        }
    }

    bool firstIsWinner(int f, int s) {
        if (f == 9 && s == 0) {
            return false;
        }
        else if (f == 0 && s == 9) {
            return true;
        }
        else {
            return f > s;
        }
    }

public:
    
    Solution() {
        cnt = 0;
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
