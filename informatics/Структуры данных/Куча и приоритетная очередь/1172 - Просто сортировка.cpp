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

    void add(int x) {
        val[size()] = x;
        _size++;
        sift_up(size() - 1);
    }

    void sift_up(int pos) {
        int p = (pos - 1) / 2;

        if (val[p] > val[pos]) {
            swap(val[p], val[pos]);
            sift_up(p);
        }
    }

    void sort() {
        for (int i = size() - 1; i > 0; i--) {
            swap(val[0], val[i]);
            sift_down(0, i);
        }
    }

    void sift_down(int pos, int k) {
        int ch1 = 2 * pos + 1;
        int ch2 = 2 * pos + 2;

        if (ch1 < k) {
            if (ch2 < k) {
                if (val[ch1] < val[pos] && val[ch1] <= val[ch2]) {
                    swap(val[ch1], val[pos]);
                    sift_down(ch1, k);
                }
                else if (val[ch2] < val[pos] && val[ch2] < val[ch1]) {
                    swap(val[ch2], val[pos]);
                    sift_down(ch2, k);
                }
            }
            else if (val[ch1] < val[pos]) {
                swap(val[ch1], val[pos]);
                sift_down(ch1, k);
            }
        }
    }

    void print() {
        for (int i = 0; i < size(); i++)
            cout << val[i] << ' ';
        cout << endl;
    }

    void reverse_print() {
        for (int i = size() - 1; i >= 0; i--)
            cout << val[i] << ' ';
        cout << endl;
    }

    int size() {
        return _size;
    }
};

class Solution {
    Heap heap;
    int n, x;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            heap.add(x);
        }
    }

    void output() {
        heap.reverse_print();
    }

    void solution() {
        heap.sort();
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
