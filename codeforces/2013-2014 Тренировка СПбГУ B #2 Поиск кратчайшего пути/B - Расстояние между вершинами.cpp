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
const int N = 7e4+5;
const int mod = 1e9+7;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, m, s, f;
vector<pii> g[N];
vector<int> d(N, inf), p(N, -1), path;

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
    set<pii> q;
    q.insert(mp(d[s], s));
    while (!q.empty()) {
        int v = q.begin()->S;
        q.erase(q.begin());
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i].F,
            len = g[v][i].S;
            if (d[to] > d[v]+len) {
                q.erase(mp(d[to], to));
                d[to] = d[v]+len;
                p[to] = v;
                q.insert(mp(d[to], to));
            }
        }
    }
    if (d[f] != inf) {
        path.pb(f);
        for (int i = p[f]; i != -1; i = p[i])
            path.pb(i);
    }
}

void output() {
    if (d[f] != inf) {
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