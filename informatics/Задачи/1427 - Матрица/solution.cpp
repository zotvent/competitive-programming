#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstring>

using namespace std;

#define F first
#define S second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 755;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

int n, m, g[N][N], res = 0;
vector<int> min_in_row(N, inf), max_in_col(N, -inf);

void input() {
    speed
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        min_in_row[i] = g[i][1];
        for (int j = 1; j <= m; j++)
            min_in_row[i] = min(min_in_row[i], g[i][j]);
    }
    
    for (int i = 1; i <= m; i++) {
        max_in_col[i] = g[1][i];
        for (int j = 1; j <= n; j++)
            max_in_col[i] = max(max_in_col[i], g[j][i]);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j] == min_in_row[i] && g[i][j] == max_in_col[j])
                res++;
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
