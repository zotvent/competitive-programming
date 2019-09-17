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
const int N = 1e3 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int n, m, k, res;
    vector<int> a, raft;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> m;
        raft.resize(n * m);
        for (int i = 0; i < n * m; i++) {
            cin >> raft[i];
        }
        cin >> k;
        a.resize(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
    }

    void prepare() {
    }

    void output() {
        cout << res;
    }

    void solution() {
        quadratic_sort(raft, n * m);
        quadratic_sort(a, k);

        res = 0;
        int ri = 0, ai = 0;

        while (ri < n * m && ai < k) {
            if (a[ai] <= raft[ri]) {
                ++res;
                ++ai;
                ++ri;
            }
            else {
                ++ri;
            }
        }
    }

    void quadratic_sort(vector<int> &v, int size) {
        int hole, value;
        for (int i = 1; i < size; i++) {
            hole = i;
            value = v[i];

            while (hole > 0 && value < v[hole - 1]) {
                v[hole] = v[hole - 1];
                --hole;
            }

            v[hole] = value;
        }
    }

public:

    Solution() {
    }

    void solve() {
        prepare();
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
