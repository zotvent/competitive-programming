#include <stdio.h>
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

const int inf = 1e9;
const int N = 1005;
const int mod = 1e9+7;
const int MAX = 2500;

using namespace std;

int n, a[N], m, l, r, t[4*N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }

    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = min(t[2*v], t[2*v+1]);
}

int getMin(int v, int tl, int tr, int l, int r) {
    if (l > r) return inf;

    if (l <= tl && tr <= r) return t[v];

    int tm = (tl+tr)/2;
    int a = getMin(2*v, tl, tm, l, min(r, tm)),
        b = getMin(2*v+1, tm+1, tr, max(l, tm+1), r);
    return min(a, b);
}

int main() {
    speed
    freopen("stupid_rmq.in", "r", stdin);
    freopen("stupid_rmq.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        cout << getMin(1, 1, n, l, r) << endl;
    }
    return 0;
}