#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define For(i, start, end) for (int (i) = (start); (i) < (end); (i)++)
#define rof(i, start, end) for (int (i) = (start); (i) > (end); (i)--)
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair

const int INF = 2000000000;

using namespace std;

int n, s = 0, deg;
vector<vector<int>> g;
vector<int> path;

void findEulerPath(int v) {
    For(i, 0, n) {
        if (g[v][i] > 0) {
            g[v][i]--;
            g[i][v]--;
            findEulerPath(i);
        }
    }
    path.push_back(v);
}

int main() {
    freopen("post.in", "r", stdin);
    freopen("post.out", "w", stdout);

    scanf("%d", &n);
    g.resize(n);
    For(i, 0, n) {
        g[i].resize(n);
        scanf("%d", &deg);
        For(j, 0, deg) {
            int to, len;
            scanf("%d%d", &to, &len);
            g[i][to-1]++;
        }
        if (deg & 1) s = i;
    }

    findEulerPath(s);

    printf("%d\n", path.size()-1);
    For(i, 0, path.size()) {
        if (i) printf(" ");
        printf("%d", path[i]+1);
    }

    return 0;
}