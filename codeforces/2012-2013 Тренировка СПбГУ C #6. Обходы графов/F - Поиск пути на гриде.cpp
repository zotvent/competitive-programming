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

int w, h, x[3], y[3], used[N][N];
char grid[N][N];
int dx[N] = {1, -1, 0, 0};
int dy[N] = {0, 0, 1, -1};
pii p[N][N];
vector<pii> path;

void input() {
    speed
    freopen("dfsongrid.in", "r", stdin);
    freopen("dfsongrid.out", "w", stdout);
    cin >> w >> h >> y[1] >> x[1] >> y[2] >> x[2];
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> grid[i][j];
}

bool valid(int x, int y) {
    return x >= 1 && x <= h && y >= 1 && y <= w;
}

void dfs(int row, int column) {
    used[row][column] = 1;
    for (int i = 0; i < 4; i++) {
        int x = dx[i]+row;
        int y = dy[i]+column;
        if (valid(x, y)) {
            if (grid[x][y] == '.' && !used[x][y]) {
                p[x][y] = mp(row, column);
                dfs(x, y);
            }
        }
    }
}

void solve() {
    dfs(x[1], y[1]);
    if (used[x[2]][y[2]]) {
        p[x[1]][y[1]] = mp(-1, -1);
        path.pb(mp(x[2], y[2]));
        for (pii i = p[x[2]][y[2]]; i != mp(-1, -1); i = p[i.F][i.S])
            path.pb(i);
    }
}

void output() {
    if (path.size() > 0) {
        cout << "YES" << endl;
        for (int i = path.size()-1; i >= 0; i--)
            cout << path[i].S << ' ' << path[i].F << ' ';
    }
    else
        cout << "NO";
}

int main() {
    input();
    solve();
    output();
    return 0;
}
