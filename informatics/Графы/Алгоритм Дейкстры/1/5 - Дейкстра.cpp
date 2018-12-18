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
const int N = 105;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, s, f, g[N][N];
    vector<int> d;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> s >> f;
        prepare();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];
    }
    
    void prepare() {
        d.assign(N, inf);
    }
    
    void output() {
        cout << (d[f] == inf ? -1 : d[f]);
    }
    
    void solution() {
        dijkstra();
    }

    void dijkstra() {
        set<pii> q;
        d[s] = 0;
        q.insert(mp(d[s], s));

        while (!q.empty()) {
            int v = q.begin()->S;
            q.erase(q.begin());

            for (int i = 1; i <= n; i++) {
                int to = i;
                int len = g[v][i];

                if (len > 0 && d[to] > d[v] + len) {
                    q.erase(mp(d[to], to));
                    d[to] = d[v] + len;
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
