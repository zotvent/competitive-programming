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
const int N = 1e5+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

struct Heap {

private:
    int _size;
    int val[N];

public:
    Heap() {
        _size = 0;
    }

    int add(int x) {
        val[size()] = x;
        _size++;
        return sift_up(size() - 1);
    }

    int sift_up(int pos) {
        if (!pos) return 0;
        int p = (pos - 1) / 2;

        if (val[p] < val[pos]) {
            swap(val[p], val[pos]);
            return sift_up(p);
        }

        return pos;
    }

    int sift_down(int pos) {
        int ch1 = 2 * pos + 1;
        int ch2 = 2 * pos + 2;

        if (ch1 < size()) {
            if (ch2 < size()) {
                if (val[ch1] > val[pos] && val[ch1] >= val[ch2]) {
                    swap(val[ch1], val[pos]);
                    return sift_down(ch1);
                }
                else if (val[ch2] > val[pos] && val[ch2] >= val[ch1]) {
                    swap(val[ch2], val[pos]);
                    return sift_down(ch2);
                }
            }
            else if (val[ch1] > val[pos]) {
                swap(val[ch1], val[pos]);
                return sift_down(ch1);
            }
        }

        return pos;
    }

    int increase(int index, int x) {
        val[index] += x;
        return sift_up(index);
    }

    int decrease(int index, int x) {
        val[index] -= x;
        return sift_down(index);
    }

    int get_max() {
        return val[0];
    }

    int extract_max() {
        val[0] = val[size() - 1];
        _size--;
        return sift_down(0);
    }

    void print() {
        for (int i = 0; i < size(); i++)
            cout << val[i] << ' ';
    }

    int size() {
        return _size;
    }
};

struct PriorityQueue {

private:
    Heap heap;
    int capacity;

public:
    PriorityQueue() {
        capacity = 0;
    }

    PriorityQueue(int x) {
        capacity = x;
    }

    int enqueue(int x) {
        if (heap.size() == capacity) 
            return -1;
        return heap.add(x);
    }

    pii dequeue() {
        if (!heap.size()) 
            return mp(-1, -1);

        int mx = heap.get_max();
        int index = heap.extract_max();

        if (!heap.size()) index = -2;

        return mp(index, mx);
    }

    void print() {
        heap.print();
    }
};

class Solution {
    PriorityQueue queue;
    int n, m, type, x, res;
    pii mx;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> m;
        queue = PriorityQueue(n);
        for (int i = 0; i < m; i++) {
            cin >> type;
            if (type == 1) {
                mx = queue.dequeue();
                if (mx.F == -1)
                    cout << -1 << endl;
                else {
                    if (mx.F == -2) mx.F = 0;
                    else mx.F++;
                    
                    cout << mx.F << ' ' << mx.S << endl;
                }
            } 
            else {
                cin >> x;
                res = queue.enqueue(x);
                if (res != -1) res++;
                cout << res << endl;
            }
        }
    }

    void output() {
    }

    void solution() {
        queue.print();
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
