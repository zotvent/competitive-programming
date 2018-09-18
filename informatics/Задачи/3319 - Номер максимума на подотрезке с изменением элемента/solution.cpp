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
const int N = 1e5+5;
const int mod = 1e9+7;

using namespace std;

int n, a[N], k, l, r;
pii t[4*N];
char command;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = mp(a[tl], tl);
        return;
    }

    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = max(t[2*v], t[2*v+1]);
}

void update(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
        t[v].F = x;
        return;
    }

    int tm = (tl+tr)/2;
    if (i <= tm)
        update(2*v, tl, tm, i, x);
    else
        update(2*v+1, tm+1, tr, i, x);
    t[v] = max(t[2*v], t[2*v+1]);
}

pii getMax(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return mp(-inf, 0);

    if (l <= tl && tr <= r)
        return t[v];

    int tm = (tl+tr)/2;
    pii a = getMax(2*v, tl, tm, l, min(tm, r)),
    b = getMax(2*v+1, tm+1, tr, max(l, tm+1), r);

    return max(a, b);
}

int main() {
    speed
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> command >> l >> r;
        if (command == 'u')
            update(1, 1, n, l, r);
        else {
            pii ans = getMax(1, 1, n, l, r);
            cout << ans.S << ' ';
        }
    }
    return 0;
}