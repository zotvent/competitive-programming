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
    int n, m, d[50][50] = {0};

    cin >> n >> m;
    d[0][0] = 1;
    For(i, 0, n)
        For(j, 0, m) {
            if (i < n-1 && j < m-2)
                d[i+1][j+2] += d[i][j];
            if (i < n-2 && j < m-1)
                d[i+2][j+1] += d[i][j];
        }

    cout << d[n-1][m-1];

    return 0;
}