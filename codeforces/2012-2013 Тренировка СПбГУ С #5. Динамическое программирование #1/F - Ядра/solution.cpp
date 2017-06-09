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

const int INF = 1e9, MAXN = 3*1e5+5;

using namespace std;

int t, m[25], a[MAXN], b[MAXN], n = 1;
vector<int> d(2*MAXN, INF);

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) cin >> m[i];

    b[1] = 1;
    for (int i = 2; ; i++) {
        b[i] = b[i - 1] + i;
        if (b[i] > MAXN) break;
    }

    a[1] = 1;
    for (int i = 2; ; i++) {
        a[i] = a[i - 1] + b[i];
        n++;
        if (a[i] > MAXN) break;
    }

    d[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= MAXN-a[i]; j++) {
            int d1 = d[j+a[i]], d2 = d[j]+1;
            d[j+a[i]] = min(d1, d2);
        }
    }

    for (int i = 1; i <= t; i++) {
        if (i-1) cout << endl;
        cout << d[m[i]];
    }

    return 0;
}