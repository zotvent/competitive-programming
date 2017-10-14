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
const int N = 2005;
const int mod = 1e9+7;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, s, f, g[N][N], used[N];
vector<int> d(N, inf);

void input() {
    speed
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);
    cin >> n >> s >> f;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
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
        for (int j = 1; j <= n; j++)
            if (g[v][j] != -1)
                if (d[j] > d[v]+g[v][j])
                    d[j] = d[v]+g[v][j];
    }
}

void output() {
    cout << (used[f] ? d[f] : -1);
}

int main() {
    input();
    solve();
    output();
    return 0;
}