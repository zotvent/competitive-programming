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
    int n, f[1000+5];
    f[0] = 1, f[1] = 1;

    cin >> n;
    For(i, 2, n+1)
        f[i] = (f[i-1] + f[i-2])%10;

    cout << f[n];

    return 0;
}