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
    int n, m, a[N];
    vector<int> g[N];
    vector<int> d;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; i++) {
            int from, to;
            cin >> from >> to;
            g[from].pb(to);
            g[to].pb(from);
        }
        prepare();
    }
    
    void prepare() {
        d.assign(N, inf);
    }
    
    void output() {
        cout << (d[n] < inf ? d[n] - a[n] : -1);
    }
    
    void solution() {
        djikstra();
    }

    void djikstra() {
        set<pii> q;
        d[1] = a[1];
        q.insert(mp(d[1], 1));

        while (!q.empty()) {
            int v = q.begin()->S;
            q.erase(q.begin());

            for (int i = 0; i < g[v].size(); i++) {
                int to = g[v][i];
                int len = d[v] + a[to];

                if (d[to] > len) {
                    q.erase(mp(d[to], to));
                    d[to] = len;
                    q.insert(mp(d[to], to));
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
