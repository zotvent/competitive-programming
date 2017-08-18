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

int n, m, a[1001], b[1001];
const int INF = 2000000000;

void lcs() {
    vector<vector<int>> d(n+1, vector<int>(m+1, 0));

    For(i, 0, n+1) d[i][0] = 0;
    For(j, 0, m+1) d[0][j] = 0;

    For(i, 1, n+1)
        For(j, 1, m+1)
            if (a[i] == b[j])
                d[i][j] = d[i-1][j-1]+1;
            else d[i][j] = max(d[i-1][j], d[i][j-1]);

    cout << d[n][m];
}

int main() {
    cin >> n;
    For(i, 1, n+1)
        cin >> a[i];
    cin >> m;
    For(i, 1, m+1)
        cin >> b[i];

    lcs();

    return 0;
}