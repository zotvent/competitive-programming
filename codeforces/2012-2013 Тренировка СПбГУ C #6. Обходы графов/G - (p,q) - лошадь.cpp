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

int m, n, p, q, x[3], y[3], dx[8], dy[8], used[N][N];
pii parent[N][N];
vector<pii> path;

void input() {
    speed
    freopen("horse.in", "r", stdin);
    freopen("horse.out", "w", stdout);
    cin >> m >> n >> p >> q >> x[1] >> y[1] >> x[2] >> y[2];
    dx[0] = dx[1] = dy[5] = dy[7] = p;
    dx[2] = dx[3] = dy[4] = dy[6] = -p;
    dx[4] = dx[5] = dy[1] = dy[3] = q;
    dx[6] = dx[7] = dy[0] = dy[2] = -q;
    
    // dx[0] = dx[1] = p;
    // dy[0] = -q;
    // dy[1] = q;
    
    // dx[2] = dx[3] = -p;
    // dy[2] = -q;
    // dy[3] = q;
    
    // dx[4] = dx[5] = q;
    // dy[4] = -p;
    // dy[5] = p;
    
    // dx[6] = dx[7] = -q;
    // dy[6] = -p;
    // dy[7] = p;
}

bool valid(int x, int y) {
    return x >= 1 && x <= m && y >= 1 && y <= n;
}

void bfs(int sx, int sy) {
    used[sx][sy] = 1;
    queue<pii> q;
    q.push(mp(sx, sy));
    while (!q.empty()) {
        int row = q.front().F;
        int column = q.front().S;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x = row+dx[i];
            int y = column+dy[i];
            if (valid(x, y)) {
                if (!used[x][y]) {
                    parent[x][y] = mp(row, column);
                    used[x][y] = 1;
                    q.push(mp(x, y));
                }
            }
        }
    }
}

void solve() {
    bfs(x[1], y[1]);
    if (used[x[2]][y[2]]) {
        parent[x[1]][y[1]] = mp(-1, -1);
        path.pb(mp(x[2], y[2]));
        for (pii i = parent[x[2]][y[2]]; i != mp(-1, -1); i = parent[i.F][i.S])
            path.pb(i);
    }
}

void output() {
    if (path.size() > 0) {
        cout << path.size()-1 << endl;
        for (int i = path.size()-1; i >= 0; i--)
            cout << path[i].F << ' ' << path[i].S << endl;
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
