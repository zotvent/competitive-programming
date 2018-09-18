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

    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> d(n, vector<int>(m, 0));
    d[0][0] = 1;
    For(i, 0, n)
        For(j, 0, m)
            cin >> a[i][j];
    For(i, 0, n)
        For(j, 0, m) {
            if (i < n-1 && a[i+1][j])
                d[i+1][j] += d[i][j];
            if (j < m-1 && a[i][j+1])
                d[i][j+1] += d[i][j];
        }

    if (d[n-1][m-1]) cout << d[n-1][m-1];
    else cout << "Impossible";

    return 0;
}