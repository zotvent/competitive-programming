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

const int INF = 2000000000;

using namespace std;

int main() {
    int n;
    cin >> n;

    int d[n+1];
    d[0] = 0;
    For(i, 1, n+1) {
        d[i] = INF;
        for (int j = 1; j*j*j <= n; j++) 
            if (i >= j*j*j && d[i-j*j*j]+1 < d[i])
                d[i] = d[i-j*j*j]+1;
    }

    cout << d[n];

    return 0;
}