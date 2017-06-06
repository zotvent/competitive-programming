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
    int n;

    cin >> n;
    vector<int> d(n+5, INF);
    d[0] = 0, d[1] = 0;
    For(i, 1, n+1) {
        d[i] = min(d[i], d[i-1]+1);
        if (i*2 <= n)
            d[i*2] = min(d[i*2], d[i]+1);
        if (i*3 <= n)
            d[i*3] = min(d[i*3], d[i]+1);
    }

    cout << d[n];

    return 0;
}