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
    int n, d[31+5][31+5] = {0};

    cin >> n;
    d[1][1] = 1;
    For(i, 2, n+1) {
        For(j, 1, i+1) {
            d[i][j] = d[i-1][j-1] + d[i-1][j];
        }
    }

    For(i, 1, n+1) {
        For(j, 1, i+1)
            cout << d[i][j] << " ";
        cout << "\n";
    }

    return 0;
}