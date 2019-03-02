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
const int N = 1e5 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int n, a[N];

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void prepare() {
    }

    void output() {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
    }

    void solution() {
        merge_sort(0, n);
    }

    void merge_sort(int l, int r) {
        if (r - l < 2) {
            return;
        }

        int size = r - l;
        int m = l + (r - l) / 2;

        merge_sort(l, m);
        merge_sort(m, r);

        int li = l;
        int ri = m;
        int i = 0;

        int *sorted_array = new int [size];

        while (li < m || ri < r) {
            if (li == m) {
                copy(a + ri, a + r, sorted_array + i);
                ri = r;
            }
            else if (ri == r) {
                copy(a + li, a + m, sorted_array + i);
                li = m;
            }
            else if (a[li] < a[ri]) {
                sorted_array[i++] = a[li++];
            }
            else {
                sorted_array[i++] = a[ri++];
            }
        }

        copy(sorted_array, sorted_array + size, a + l);
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
