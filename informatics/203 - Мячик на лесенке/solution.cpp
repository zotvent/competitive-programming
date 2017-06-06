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
    int n, d[35] = {0};
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    cin >> n;
    For(i, 4, n+1)
        d[i] = d[i-1] + d[i-2] + d[i-3];

    cout << d[n];

    return 0;
}