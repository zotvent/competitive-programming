#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int INF = 1e9, MAXN = 1e4+5;

using namespace std;

int n, m, d[MAXN], mx = 0;

int main() {
    freopen("longpath.in", "r", stdin);
    freopen("longpath.out", "w", stdout);
    speed
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int b, e;
        cin >> b >> e;
        d[e] = max(d[e], d[b]+1);
    }

    for (int i = 1; i <= n; i++) mx = max(mx, d[i]);

    cout << mx;

    return 0;
}