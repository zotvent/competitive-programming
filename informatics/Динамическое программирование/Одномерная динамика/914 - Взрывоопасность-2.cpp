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
const int N = 25;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int n, dp[N][3][3];

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
    }

    void prepare() {
    }

    void output() {
        if (n == 1) {
            cout << 3;
        }
        else {
            int ax = dp[n][0][1] + dp[n][0][2];
            int bx = dp[n][1][0] + dp[n][1][1] + dp[n][1][2];
            int cx = dp[n][2][0] + dp[n][2][1] + dp[n][2][2];
            cout << ax + bx + cx;
        }
    }

    void solution() {
        dp[2][0][1] = 1;
        dp[2][0][2] = 1;

        dp[2][1][0] = 1;
        dp[2][1][1] = 1;
        dp[2][1][2] = 1;

        dp[2][2][0] = 1;
        dp[2][2][1] = 1;
        dp[2][2][2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i][0][1] = dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2];
            dp[i][0][2] = dp[i - 1][2][0] + dp[i - 1][2][1] + dp[i - 1][2][2];

            dp[i][1][0] = dp[i - 1][0][1] + dp[i - 1][0][2];
            dp[i][1][1] = dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2];
            dp[i][1][2] = dp[i - 1][2][0] + dp[i - 1][2][1] + dp[i - 1][2][2];

            dp[i][2][0] = dp[i - 1][0][1] + dp[i - 1][0][2];
            dp[i][2][1] = dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2];
            dp[i][2][2] = dp[i - 1][2][0] + dp[i - 1][2][1] + dp[i - 1][2][2];
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
