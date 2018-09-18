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
const int N = 105;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

int x, n, g[N][N];
vector<int> res(N, 0);

void input() {
    speed
    cin >> x >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
}

void solve() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[j][i] == x)
                res[i] = 1;
}

void output() {
    for (int i = 1; i <= n; i++)
        cout << (res[i] ? "YES" : "NO") << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
