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

struct el {
    int self;
    int newVal;
};

int n, a[N], k, l, r, val, j;
el t[4*N];
char command;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].self = a[tl];
        t[v].newVal = -1;
        return;
    }

    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = t[2*v];
}

void push(int v, int tl, int tr) {
    if (t[v].newVal != -1) {
        int x = t[v].newVal;
        t[v].newVal = -1;
        t[v].self = x;

        t[2*v].newVal = x;
        t[2*v].self = x;

        t[2*v+1].newVal = x;
        t[2*v+1].self = x;
    }
}

void update(int v, int tl, int tr, int l, int r, int a) {
    if (tl > r || tr < l)
        return;

    if (l <= tl && tr <= r) {
        t[v].newVal = a;
        t[v].self = a;
        return;
    }

    push(v, tl, tr);
    int tm = (tl+tr)/2;
    update(2*v, tl, tm, l, r, a);
    update(2*v+1, tm+1, tr, l, r, a);
    t[v].self = max(t[2*v].self, t[2*v+1].self);
}

int get(int v, int tl, int tr, int i) {
    if (tl == tr)
        return t[v].self;

    int tm = (tl+tr)/2;
    push(v, tl, tr);
    if (i <= tm)
        return get(2*v, tl, tm, i);
    else
        return get(2*v+1, tm+1, tr, i);
}

int main() {
    speed
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> command;
        if (command == 'g') {
            cin >> j;
            cout << get(1, 1, n, j) << ' ';
        }
        else {
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
    }
    return 0;
}