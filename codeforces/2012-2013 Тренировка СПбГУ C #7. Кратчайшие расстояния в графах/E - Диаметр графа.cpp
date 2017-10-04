#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

#define F first
#define S second
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 1e9;
const int N = 105;
const int mod = 1e9+7;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, dp[N][N], d = 0, r = inf;

void input() {
    speed
    freopen("diameter.in", "r", stdin);
    freopen("diameter.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dp[i][j];
}

bool valid(int i, int j, int k) {
    return dp[i][k] != -1 && dp[k][j] != -1;
}

void solve() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (valid(i, j, k)) {
                    if (dp[i][j] == -1)
                        dp[i][j] = dp[i][k]+dp[k][j];
                    else
                        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) {
            d = max(d, dp[i][j]);
            mx = max(mx, dp[i][j]);
        }
        r = min(r, mx);
    }
    
}

void output() {
    cout << d << endl << r;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
