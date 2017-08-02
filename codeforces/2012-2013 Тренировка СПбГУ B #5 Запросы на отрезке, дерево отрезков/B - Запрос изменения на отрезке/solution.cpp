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

const ll inf = 1e18;
const int N = 1e5+5;
const int mod = 1e9+7;

using namespace std;

int k, x, y;
ll a[N], tmin[4*N], tmax[4*N];

void buildMin(int v, int tl, int tr) {
    if (tr < tl) return;
    if (tl == tr) {
        tmin[v] = a[tl];
        return;
    }

    int tm = (tl+tr)/2;
    buildMin(2*v, tl, tm);
    buildMin(2*v+1, tm+1, tr);
    tmin[v] = min(tmin[2*v], tmin[2*v+1]);
}

void buildMax(int v, int tl, int tr) {
    if (tr < tl) return;
    if (tl == tr) {
        tmax[v] = a[tl];
        return;
    }

    int tm = (tl+tr)/2;
    buildMax(2*v, tl, tm);
    buildMax(2*v+1, tm+1, tr);
    tmax[v] = max(tmax[2*v], tmax[2*v+1]);
}

void updateMax(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
        tmax[v] = x;
        return;
    }
    int tm = (tl+tr)/2;
    if (i <= tm)
        updateMax(2*v, tl, tm, i, x);
    else
        updateMax(2*v+1, tm+1, tr, i, x);
    tmax[v] = max(tmax[2*v], tmax[2*v+1]);
}

void updateMin(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
        tmin[v] = x;
        return;
    }
    int tm = (tl+tr)/2;
    if (i <= tm)
        updateMin(2*v, tl, tm, i, x);
    else
        updateMin(2*v+1, tm+1, tr, i, x);
    tmin[v] = min(tmin[2*v], tmin[2*v+1]);
}

ll getMax(int v, int tl, int tr, int l, int r) {
    if (tr < l || tl > r) return -inf;
    if (l <= tl && tr <= r) return tmax[v];

    int tm = (tl+tr)/2;
    return max(getMax(2*v, tl, tm, l, r), getMax(2*v+1, tm+1, tr, l, r));
}

ll getMin(int v, int tl, int tr, int l, int r) {
    if (tr < l || tl > r) return inf;
    if (l <= tl && tr <= r) return tmin[v];

    int tm = (tl+tr)/2;
    return min(getMin(2*v, tl, tm, l, r), getMin(2*v+1, tm+1, tr, l, r));
}

int main() {
    speed
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);

    for (ll i = 1; i <= 1e5; i++)
        a[i] = (i*i)%12345 + (i*i*i)%23456;
    buildMin(1, 1, (int) 1e5);
    buildMax(1, 1, (int) 1e5);

    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        if (x > 0)
            cout << getMax(1, 1, (int) 1e5, x, y) - getMin(1, 1, (int) 1e5, x, y) << endl;
        else {
            updateMax(1, 1, (int) 1e5, -x, y);
            updateMin(1, 1, (int) 1e5, -x, y);
        }
    }
    return 0;
}