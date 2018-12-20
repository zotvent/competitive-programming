#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstring>

using namespace std;

#define F first
#define S second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 1e2+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, s, f, g[N][N];
    vector<int> d, p;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> s >> f;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];
        prepare();
    }
    
    void prepare() {
        d.assign(N, inf);
        p.assign(N, -1);
    }
    
    void output() {
        if (d[f] < inf) {
            vector<int> path;
            path.pb(f);
            for (int i = p[f]; i != -1; i = p[i])
                path.pb(i);
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); i++)
                cout << path[i] << ' ';
        }
        else cout << -1;
    }
    
    void solution() {
        djikstra();
    }

    void djikstra() {
        set<pii> q;
        d[s] = 0;
        q.insert(mp(0, s));

        while (!q.empty()) {
            int v = q.begin()->S;
            q.erase(q.begin());

            for (int i = 1; i <= n; i++) {
                if (g[v][i] > 0) {
                    int to = i;
                    int len = d[v] + g[v][i];

                    if (d[to] > len) {
                        q.erase(mp(d[to], to));
                        d[to] = len;
                        q.insert(mp(d[to], to));
                        p[to] = v;
                    }
                }
            }
        }
    }
    
public:
    
    Solution() {
    }
    
    void solve() {
        input();
        solution();
        output();
    }
};

int main() {
    Solution s = Solution();
    s.solve();
    return 0;
}
