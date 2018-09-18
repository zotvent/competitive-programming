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
    int n, m;
    vector<vector<int>> a(100, vector<int>(100, 0));
    vector<vector<int>> d(100, vector<int>(100, 0));

    cin >> n >> m;
    For(i, 0, n)
        For(j, 0, m)
            cin >> a[i][j];
    d[0][0] = a[0][0];
    For(i, 0, n)
        For(j, 0, m) {
            if (i < n-1)
                d[i+1][j] = max(d[i+1][j], d[i][j]+a[i+1][j]);
            if (j < m-1)
                d[i][j+1] = max(d[i][j+1], d[i][j]+a[i][j+1]);
        }

    cout << d[n-1][m-1];

    return 0;
}