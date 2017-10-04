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

int n, m, v, g[N][N], used[N], dp[N];
vector<pii> res;

void input() {
    speed
    freopen("wave.in", "r", stdin);
    freopen("wave.out", "w", stdout);
    cin >> n >> m >> v;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
}

void bfs(int s) {
    used[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (g[v][i] && !used[i]) {
                dp[i] = min(dp[i], dp[v]+1);
                used[i] = 1;
                q.push(i);
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++)
        dp[i] = inf;
    dp[v] = 0;
    bfs(v);
    for (int i = 1; i <= n; i++)
        if (used[i])
            res.pb(mp(dp[i], i));
    sort(res.begin(), res.end());
}

void output() {
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i].S << ' ';
}

int main() {
    input();
    solve();
    output();
    return 0;
}
