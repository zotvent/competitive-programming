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
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, m, used[N], g[N][N], u, v, cnt = 0;

void input() {
    speed
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
}

void dfs(int v) {
    used[v] = 1;
    for (int i = 1; i <= n; i++)
        if (g[v][i] && !used[i])
            dfs(i);
}

void solve() {
    dfs(1);
    for (int i = 1; i <= n; i++)
        cnt += used[i];
}

void output() {
    cout << (cnt == n ? "YES" : "NO");
}

int main() {
    input();
    solve();
    output();
    return 0;
}
