#include <bits/stdc++.h>

#define For(i, start, end) for (int (i) = (start); (i) < (end); (i)++)
#define rof(i, start, end) for (int (i) = (start); (i) > (end); (i)--)
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair

const int INF = 2000000000, NMAX = 4096 + 5;

using namespace std;

struct edge {
    int a, b, cost;
};

int n;
vector<edge> e;

int main() {
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);

    scanf("%d", &n);
    For(i, 0, n)
        For(j, 0, n) {
            int len;
            scanf("%d", &len);
            edge ed;
            ed.a = i;
            ed.b = j;
            ed.cost = len;
            e.push_back(ed);
        }

    For(k, 0, n) {
        vector<int> d(n, INF), p(n, -1);
        d[k] = 0;
        int x = 0;
        For(i, 0, n) {
            x = -1;
            For(j, 0, e.size())
                if (d[e[j].a] < INF && e[j].cost != 100000)
                    if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                        d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                        p[e[j].b] = e[j].a;
                        x = e[j].b;
                    }
        }

        if (x != -1) {
            int y = x;
            For(i, 0, n) y = p[y];

            vector<int> path;
            for (int cur = y;; cur = p[cur]) {
                path.push_back(cur);
                if (cur == y && path.size() > 1) break;
            }

            printf("YES\n");
            printf("%d\n", path.size()-1);
            rof(i, path.size()-1, 0)
                printf("%d ", path[i]+1);

            return 0;
        }
    }

    printf("NO");
    return 0;
}