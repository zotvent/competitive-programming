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
const int N = 5005;
const int mod = 1e9+7;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, m, s, f, used[N];
vector<int> d(N, inf), p(N, -1), path;
vector<pii> g[N];

void input() {
    speed
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);
    cin >> n >> m >> s >> f;
    for (int i = 1; i <= m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        g[a].pb(mp(b, cost));
        g[b].pb(mp(a, cost));
    }
}

void solve() {
    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        int v = -1;
        for (int j = 1; j <= n; j++)
            if (!used[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == inf)
            break;
        used[v] = 1;
        for (int j = 0; j < g[v].size(); j++) {
            int to = g[v][j].F, len = g[v][j].S;
            if (d[to] > d[v]+len) {
                d[to] = d[v]+len;
                p[to] = v;
            }
        }
    }
    if (used[f]) {
        path.pb(f);
        for (int i = p[f]; i != -1; i = p[i])
            path.pb(i);
    }
}

void output() {
    if (used[f]) {
        cout << d[f] << endl;
        for (int i = path.size()-1; i >= 0; i--)
            cout << path[i] << ' ';
    }
    else
        cout << -1;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
