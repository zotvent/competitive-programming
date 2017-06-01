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
const int N = 3*1e4+5;
const int mod = 1e9+7;
const int MAX = 2500;

using namespace std;

int n, m, a[N], t[4*N], t2[4*N], l[N], r[N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        t2[v] = t[v];
        return;
    }

    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);

    t[v] = min(t[2*v], t[2*v+1]);
    t2[v] = t[v];
}

void update(int v, int tl, int tr, int i, int val) {
    if (tl == tr) {
        t[v] = val;
        return;
    }

    int tm = (tl+tr)/2;
    if (i <= tm)
        update(2*v, tl, tm, i, val);
    else
        update(2*v+1, tm+1, tr, i, val);

    t[v] = min(t[2*v], t[2*v+1]);
}

void update2(int v, int tl, int tr, int i, int val) {
    if (tl == tr) {
        t2[v] = val;
        return;
    }

    int tm = (tl+tr)/2;
    if (i <= tm)
        update2(2*v, tl, tm, i, val);
    else
        update2(2*v+1, tm+1, tr, i, val);

    t2[v] = min(t2[2*v], t2[2*v+1]);
}

int getRight(int v, int tl, int tr, int val) {
    if (tl == tr) return tl;

    int tm = (tl+tr)/2;
    if (t[2*v] < val)
        return getRight(2*v, tl, tm, val);
    else
        return getRight(2*v+1, tm+1, tr, val);
}

int getLeft(int v, int tl, int tr, int val) {
    if (tl == tr) return tl;

    int tm = (tl+tr)/2;
    if (t2[2*v+1] < val)
        return getLeft(2*v+1, tm+1, tr, val);
    else
        return getLeft(2*v, tl, tm, val);
}

int main() {
    speed
    cin >> m;
    for (int j = 1; j <= m; j++) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        build(1, 1, n);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (t[1] < a[i]) r[i] = getRight(1, 1, n, a[i]);
            else r[i] = n+1;

            update(1, 1, n, i, inf);
        }

        for (int i = n; i > 0; i--) {
            if (t2[1] < a[i]) l[i] = getLeft(1, 1, n, a[i]);
            else l[i] = 0;

            update2(1, 1, n, i, inf);
        }

        for (int i = 1; i <= n; i++) {
            int  temp = a[i]*(r[i]-l[i]-1);
            ans = max(ans, temp);
        }
        cout << "Case " << j << ": " << ans << endl;
    }
    return 0;
}
