#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
#include <set>

#define For(i, start, end) for (int (i) = (start); (i) < (end); (i)++)
#define rof(i, start, end) for (int (i) = (start); (i) > (end); (i)--)
#define mp(i, j) make_pair (i, j)

using namespace std;

const int INF = 1000000000;

vector < pair< int, int > >  g[100000+5];

int main() {
    freopen("island2.in", "r", stdin);
    freopen("island2.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> city(n);
    For(i, 0, n)
        cin >> city[i];


    For(i, 0, m) {
        int from, to, weight = 0;
        cin >> from >> to;

        if (city[from-1] != city[to-1]) weight++;
        if (city[from-1] != city[to-1] && ((from-1) & 1)) weight++;
        g[from-1].push_back(mp(to-1, weight));

        weight = 0;
        if (city[from-1] != city[to-1]) weight++;
        if (city[from-1] != city[to-1] && ((to-1) & 1)) weight++;
        g[to-1].push_back(mp(from-1, weight));
    }

    int s = 0;
    vector<int> d (n, INF),  p (n);
    d[s] = 0;
    p[s] = -1;
    set<pair<int,int>> q;
    q.insert (make_pair (d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase (q.begin());

        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase (make_pair (d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert (make_pair (d[to], to));
            }
        }
    }

    if (d[n-1] == INF) cout << "impossible";
    else {
        vector<int> path;
        path.push_back(n - 1);
        for (int i = p[n - 1]; i != -1; i = p[i])
            path.push_back(i);

        cout << d[n - 1] << " " << path.size() << "\n";
        rof(i, path.size() - 1, -1)cout << path[i] + 1 << " ";
    }

    return 0;
}