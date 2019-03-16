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
const int N = 1e4 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int n, x[N], s;
    vector<int> dp;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
    }

    void prepare() {
    }

    void output() {
        cout << (dp[s] > 0 ? "YES" : "NO");
    }

    void solution() {
        dp.assign(s + 5, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = s - x[i]; j >= 0; j--) {
                if (dp[j] > 0) {
                    dp[j + x[i]] = 1;
                }
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
