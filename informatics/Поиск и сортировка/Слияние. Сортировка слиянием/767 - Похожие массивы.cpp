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

    int n, m, a[N], b[N];
    bool alike;

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
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
    }

    void prepare() {
    }

    void output() {
        cout << (alike ? "YES" : "NO");
    }

    void solution() {
        alike = true;

        merge_sort(&a[0], 0, n);
        merge_sort(&b[0], 0, m);

        int ai = 0, bi = 0;

        while (ai < n || bi < m) {
            if (a[ai] != b[bi]) {
                alike = false;
                break;
            }

            int tmp = a[ai];

            while (ai < n && a[ai] == tmp) {
                ai++;
            }

            while (bi < m && b[bi] == tmp) {
                bi++;
            }
        }
    }

    void merge_sort(int array[], int l, int r) {
        if (r - l < 2) {
            return;
        }

        int size = r - l;
        int m = size / 2 + l;

        merge_sort(&array[0], l, m);
        merge_sort(&array[0], m, r);

        int li = l;
        int ri = m;
        int i = 0;

        int *sortedArray = new int [size];

        while (li < m || ri < r) {
            if (li == m) {
                copy(array + ri, array + r, sortedArray + i);
                break;
            }
            else if (ri == r) {
                copy(array + li, array + m, sortedArray + i);
                break;
            }
            else if (array[li] < array[ri]) {
                sortedArray[i++] = array[li++];
            }
            else {
                sortedArray[i++] = array[ri++];
            }
        }

        copy(sortedArray, sortedArray + size, array + l);
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
