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
const int N = 305;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, m, res = 0;
vector<int> g(N, vector<int>(N, 1));

void input() {
    speed
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 0;
    }
}

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
}

void solve() {
    floyd();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res = max(res, g[i][j]);
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