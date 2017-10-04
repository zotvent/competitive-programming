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
    freopen("floyd.in", "r", stdin);
    freopen("floyd.out", "w", stdout);

    int n, g[100][100];

    cin >> n;
    For(i, 0, n)
        For(j, 0, n)
            cin >> g[i][j];

    For(k, 0, n)
        For(i, 0, n)
            For(j, 0, n)
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);

    For(i, 0, n) {
        For(j, 0, n)
            cout << g[i][j] << " ";
        cout << "\n";
    }

    return 0;
}