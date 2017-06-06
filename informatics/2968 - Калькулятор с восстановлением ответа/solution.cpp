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
    int n;

    cin >> n;
    vector<int> d(n+5, INF), p(n+5, -1);
    d[0] = 0, d[1] = 0;
    For(i, 1, n+1) {
        if (d[i] > d[i-1] + 1) {
            d[i] = d[i-1] + 1;
            p[i] = i-1;
        }
        if (i*2 <= n && d[i*2] > d[i]+1) {
            d[i * 2] = d[i] + 1;
            p[i*2] = i;
        }
        if (i*3 <= n && d[i*3] > d[i]+1) {
            d[i * 3] = d[i] + 1;
            p[i*3] = i;
        }
    }

    vector<int> path;
    path.push_back(n);
    for (int i = p[n]; i != -1; i = p[i])
        path.push_back(i);

    rof(i, path.size()-2, -1) {
        if (path[i] == path[i+1]+1) cout << 1;
        else if (path[i] == path[i+1]*2) cout << 2;
        else cout << 3;
    }

    return 0;
}