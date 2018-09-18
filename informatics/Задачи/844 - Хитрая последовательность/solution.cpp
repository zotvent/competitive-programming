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
    int n, a[1000 + 8];
    a[0] = 1, a[1] = 1, a[2] = 2, a[3] = 4;

    cin >> n;
    For(i, 2, n/2+3) {
        a[2*i] = a[i]+1;
        a[2*(i-1)+1] = a[2*(i-1)+2] + a[i-1];
    }

    cout << a[n];

    return 0;
}