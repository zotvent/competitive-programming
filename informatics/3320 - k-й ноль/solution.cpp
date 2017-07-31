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

int n, a[N], k, j;
pii t[4*N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].F = (a[tl] == 0);
        t[v].S = tl;
        return;
    }

    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v].F = t[2*v].F + t[2*v+1].F;
}

pii getZero(int v, int tl, int tr, int i) {
    if (t[v].F < i)
        return mp(-1, -1);

    if (tl == tr && t[v].F)
        return t[v];

    int tm = (tl+tr)/2;
    if (t[2*v].F >= i)
        return getZero(2*v, tl, tm, i);
    else
        return getZero(2*v+1, tm+1, tr, i-t[2*v].F);
}

int main() {
    speed
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> j;
        pii ans = getZero(1, 1, n, j);
        cout << ans.S <<  ' ';
    }
    return 0;
}