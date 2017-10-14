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
const int N = 1005;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, m, dist[N][N], res = 0;
vector<int> g[N], d;

void input() {
    speed
    freopen("sumdist.in", "r", stdin);
    freopen("sumdist.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int from, to;
        cin >> from >> to;
        g[from].pb(to);
        g[to].pb(from);
    }
}

void dijkstra(int start) {
    d.assign(N, inf);
    d[start] = 0;
    set<pii> s;
    s.insert(mp(d[start], start));
    while (!s.empty()) {
        int from = s.begin()->S;
        s.erase(s.begin());
        for (int i = 0; i < g[from].size(); i++) {
            int to = g[from][i];
            if (d[to] > d[from]+1) {
                s.erase(mp(d[to], to));
                d[to] = d[from]+1;
                s.insert(mp(d[to], to));
            }
        }
    }
}

void update(int s) {
    for (int i = 1; i <= n; i++)
        dist[s][i] = d[i];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        update(i);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res += dist[i][j];
}

void output() {
    cout << res/2;
}

int main() {
    input();
    solve();
    output();
    return 0;
}