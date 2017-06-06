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
    double a[20 + 8][2];
    // 0-A, 1-B
    a[1][0] = 1, a[1][1] = 1;

    cin >> n;
    For(i, 2, n+1) {
        a[i][0] = a[i-1][1];
        a[i][1] = a[i-1][0] + a[i-1][1];
    }

    cout << a[n][0] + a[n][1];

    return 0;
}