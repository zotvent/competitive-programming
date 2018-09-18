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
    int n, a[1000+5];
    a[0] = 1, a[1] = 1;

    cin >> n;
    For(i, 2, n+1) {
        if (i & 1)
            a[i] = a[i / 2] - a[(i / 2) - 1];
        else
            a[i] = a[i / 2] + a[(i / 2) - 1];
    }

    cout << a[n];

    return 0;
}