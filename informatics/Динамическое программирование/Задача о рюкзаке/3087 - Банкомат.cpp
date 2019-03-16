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
const int N = 1e2 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int n, x[N], s;
    vector<int> dp, p;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        cin >> s;
    }

    void prepare() {
    }

    void output() {
        if (dp[s] == inf) {
            cout << "No solution";
        }
        else {
            int prev = s;
            for (int i = p[s]; i != -1; i = p[i]) {
                cout << prev - i << ' ';
                prev = i;
            }
        }
    }

    void solution() {
        dp.assign(s + 5, inf);
        p.assign(s + 5, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= s - x[i]; j++) {
                if (dp[j] < inf && dp[j + x[i]] > dp[j] + 1) {
                    dp[j + x[i]] = dp[j] + 1;
                    p[j + x[i]] = j;
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
