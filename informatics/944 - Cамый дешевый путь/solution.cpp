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

const int INF = 2000000000;

int main() {
    int n, m, a[20][20];

    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(m, INF));
    For(i, 0, n)
        For(j, 0, m)
            cin >> a[i][j];

    d[0][0] = 0;
    For(i, 0, n) {
        For(j, 0, m) {
            if (i < n-1)
                d[i+1][j] = min(d[i+1][j], d[i][j] + a[i][j]);
            if (j < m-1)
                d[i][j+1] = min(d[i][j+1], d[i][j] + a[i][j]);
        }
    }

    cout << d[n-1][m-1] + a[n-1][m-1];

    return 0;
}