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
const int N = 205;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, m, res = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char a[N][N];

void input() {
    speed
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}

bool valid(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= m;
}

void dfs(int row, int column) {
    for (int i = 0; i < 4; i++) {
        int x = row + dx[i];
        int y = column + dy[i];
        if (valid(x, y))
            if (a[x][y] == '#') {
                a[x][y] = '.';
                dfs(x, y);
            }
    }
}

void solve() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            if (a[i][j] == '#') {
                dfs(i, j);
                res++;
            }
}

void output() {
    cout << res;
}

int main() {
    input();
    solve();
    output();
    return 0;
}