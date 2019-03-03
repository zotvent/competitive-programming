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

    int n, res;
    vector<int> a;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void prepare() {
    }

    void output() {
        cout << res;
    }

    void solution() {
        quick_sort(a, 0, n);

        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i - 1]) {
                res++;
            }
        }
    }

    void quick_sort(vector<int> &array, int l, int r) {
        if (l < r) {
            int q = random_partition(array, l, r);
            if (q == -1) {
                return;
            }
            quick_sort(array, l, q);
            quick_sort(array, q + 1, r);
        }
    }

    int random_partition(vector<int> &array, int l, int r) {
        int i = rand() % (r - l);
        swap(array[l + i], array[r - 1]);
        return partition(array, l, r);
    }

    int partition(vector<int> &array, int l, int r) {
        int x = array[r - 1];
        int i = l - 1;
        int cnt = 0;

        for (int j = l; j < r - 1; j++) {
            if (array[j] <= x) {
                cnt += (array[j] == x ? 1 : 0);
                swap(array[++i], array[j]);
            }
        }

        swap(array[++i], array[r - 1]);

        // case if all numbers are equal
        if (cnt == r - l - 1) {
            i = -1;
        }

        return i;
    }

public:

    Solution() {
        res = 0;
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
