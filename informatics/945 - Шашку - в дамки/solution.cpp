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
    int x, y, d[8][8] = {0};

    cin >> y >> x;
    x--; y--;

    d[x][y] = 1;
    For(i, x, 8)
        For(j, 0, 8)
            if (i < 7) {
                if (j > 0)
                    d[i+1][j-1] += d[i][j];
                if (j < 7)
                    d[i+1][j+1] += d[i][j];
            }

    int sum = 0;
    For(i, 0, 8)
        sum += d[7][i];
    cout << sum;

    return 0;
}