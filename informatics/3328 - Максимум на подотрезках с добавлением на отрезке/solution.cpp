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
    int max;
    int add;
};

int n, a[N], k, l, r, add, j;
el t[4*N];
char command;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].max = a[tl];
        t[v].add = 0;
        return;
    }

    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v].max = max(t[2*v].max, t[2*v+1].max);
}

void push(int v, int tl, int tr) {
    if (t[v].add != 0) {
        int x = t[v].add;
        t[v].add = 0;

        t[2*v].add += x;
        t[2*v].max += x;

        t[2*v+1].add += x;
        t[2*v+1].max += x;
    }
}

void update(int v, int tl, int tr, int l, int r, int a) {
    if (tl > r || tr < l)
        return;

    if (l <= tl && tr <= r) {
        t[v].add += a;
        t[v].max += a;
        return;
    }

    push(v, tl, tr);
    int tm = (tl+tr)/2;
    update(2*v, tl, tm, l, r, a);
    update(2*v+1, tm+1, tr, l, r, a);
    t[v].max = max(t[2*v].max, t[2*v+1].max);
}

int getMax(int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l)
        return -inf;

    if (l <= tl && tr <= r)
        return t[v].max;

    int tm = (tl+tr)/2;
    push(v, tl, tr);

    int a = getMax(2*v, tl, tm, l, r),
    b = getMax(2*v+1, tm+1, tr, l, r);
    return max(a, b);
}

int main() {
    speed
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> command;
        if (command == 'm') {
            cin >> l >> r;
            cout << getMax(1, 1, n, l, r) << ' ';
        }
        else {
            cin >> l >> r >> add;
            update(1, 1, n, l, r, add);
        }
    }
    return 0;
}