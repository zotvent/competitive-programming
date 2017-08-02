#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 2e9;
const int N = 1e5+5;
const int mod = 1e9+7;

using namespace std;

ll a[N], t[4*N];
int n, m, l, r;

void build(int v, int tl, int tr) {
    if (tr < tl) return;
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }

    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = t[2*v] + t[2*v+1];
}

ll getSum(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return 0;
    if (l <= tl && tr <= r)
        return t[v];

    int tm = (tl+tr)/2;
    return getSum(2*v, tl, tm, l, r) + getSum(2*v+1, tm+1, tr, l, r);
}

int main() {
    speed
    freopen("sum2.in", "r", stdin);
    freopen("sum2.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        cout << getSum(1, 1, n, l, r) << endl;
    }
    return 0;
}