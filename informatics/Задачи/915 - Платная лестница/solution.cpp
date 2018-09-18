#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

#define For(i, start, end) for (int (i) = (start); (i) < (end); (i)++)
#define rof(i, start, end) for (int (i) = (start); (i) > (end); (i)--)
#define mp(i, j) make_pair (i, j)

using namespace std;

const int INF = 1000000000;

int main() {
    int n, a[101];
    vector<int> d(100+5, INF);
    d[0] = 0;

    cin >> n;
    For(i, 0, n)
        cin >> a[i];
    d[1] = a[0];
    For(i, 2, n+1) {
        d[i] = min(d[i], d[i-1] + a[i-1]);
        d[i] = min(d[i], d[i-2] + a[i-1]);
    }

    cout << d[n];

    return 0;
}