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
    double a[40 + 8][2][2];
    a[2][0][0] = 1, a[2][0][1] = 1;
    a[2][1][0] = 1, a[2][1][1] = 1;

    cin >> n;
    For(i, 3, n + 1) {
        a[i][0][0] = a[i - 1][0][0] + a[i - 1][1][0];
        a[i][0][1] = a[i - 1][0][0] + a[i - 1][1][0];
        a[i][1][0] = a[i - 1][0][1] + a[i-1][1][1];
        a[i][1][1] = a[i - 1][0][1];
    }

    if (n == 1) cout << 2;
    else printf("%.0f", a[n][0][0] + a[n][0][1] + a[n][1][0] + a[n][1][1]);

    return 0;
}