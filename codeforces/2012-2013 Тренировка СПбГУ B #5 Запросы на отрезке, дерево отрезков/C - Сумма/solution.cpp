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
const int N = 100005;
const int mod = 1e9+7;
const int MAX = 2500;

using namespace std;

struct node {
    ll x = -1;
    ll val = 0;
};

node t[4*N];
int n, k, l, r, x;
char type;

ll toLong(int x) {
    return (ll) x;
}

void push(int v, int tl, int tr) {
    if (t[v].x != -1) {
        ll val = t[v].x;
        int tm = (tl+tr)/2;

        t[2*v].val = toLong(tm-tl+1)*val;
        t[2*v].x = val;
        t[2*v+1].val = toLong(tr-tm)*val;
        t[2*v+1].x = val;

        t[v].x = -1;
    }
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return;

    if (l <= tl && tr <= r) {
        t[v].x = x;
        t[v].val = toLong(x) * toLong(tr-tl+1);
        return;
    }

    int tm = (tl+tr)/2;
    push(v, tl, tr);
    update(2*v, tl, tm, l, min(r, tm), x);
    update(2*v+1, tm+1, tr, max(l, tm+1), r, x);
    t[v].val = t[2*v].val + t[2*v+1].val;
}

ll getSum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;

    if (l <= tl && tr <= r) return t[v].val;

    int tm = (tl+tr)/2;
    push(v, tl, tr);
    ll a = getSum(2*v, tl, tm, l, min(r, tm));
    ll b = getSum(2*v+1, tm+1, tr, max(l, tm+1), r);
    return a + b;
}

int main() {
    speed
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> type >> l >> r;
        if (type == 'A') {
            cin >> x;
            update(1, 1, n, l, r, x);
        }
        else cout << getSum(1, 1, n, l, r) << endl;
    }
    return 0;
}