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
#include <climits>

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
const int N = 1e6 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int n, a[N];
    vector<int> dp, p;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
        dp.assign(N, INT_MAX);
        p.assign(N, -1);
    }

    void prepare() {
    }

    void output() {
        vector<int> path;
        int to = n;

        for (int i = p[n]; i != -1; i = p[i]) {
            int from = i;

            if (to == from + 1) {
                path.pb(1);
            }
            else if (to == from * 2) {
                path.pb(2);
            }
            else if (to == from * 3) {
                path.pb(3);
            }

            to = from;
        }

        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
        }
    }

    void solution() {
        dp[1] = 0;

        for (int i = 1; i < n; i++) {
            int plus1 = i + 1;
            int x2 = i * 2;
            int x3 = i * 3;

            if (plus1 <= n && dp[plus1] > dp[i] + 1) {
                dp[plus1] = dp[i] + 1;
                p[plus1] = i;
            }
            if (x2 <= n && dp[x2] > dp[i] + 1) {
                dp[x2] = dp[i] + 1;
                p[x2] = i;
            }
            if (x3 <= n && dp[x3] > dp[i] + 1) {
                dp[x3] = dp[i] + 1;
                p[x3] = i;
            }
        }
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
