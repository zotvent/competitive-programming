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
const int N = 2e4+5;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, m, used[N], a[N], cnt = 1;
vector<int> g[N];

void input() {
    speed
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int from, to;
        cin >> from >> to;
        g[from].pb(to);
        g[to].pb(from);
    }
}

void dfs(int v) {
    used[v] = 1;
    a[v] = cnt;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

void solve() {
    for (int i = 1; i <= n; i++)
        if (!used[i]) {
            dfs(i);
            cnt++;
        }
}

void output() {
    cout << cnt-1 << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
}

int main() {
    input();
    solve();
    output();
    return 0;
}