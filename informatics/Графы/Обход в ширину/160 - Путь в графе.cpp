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
const int N = 1e2 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, g[N][N], s, e, res;
    vector<int> used, d, p;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
        prepare();
        for (int i = 1 ; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];
        cin >> s >> e;
    }

    void prepare() {
        used.assign(n + 1, 0);
        d.assign(n + 1, inf);
        p.assign(n + 1, -1);
    }
    
    void output() {
        if (d[e] != inf) {
            vector<int> path;
            path.pb(e);
            for (int i = p[e]; i != -1; i = p[i])
                path.pb(i);
            reverse(path.begin(), path.end());

            res = path.size() - 1;
            cout << res << endl;
            if (res) {
                for (int i = 0; i < path.size(); i++)
                    cout << path[i] << ' ';
            }
        }
        else cout << -1;
    }
    
    void solution() {
        bfs(s);
    }

    void bfs(int s) {
        queue<int> q;
        q.push(s);
        d[s] = 0;
        used[s] = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 1; i <= n; i++) {
                if (!used[i] && g[v][i]) {
                    used[i] = 1;
                    d[i] = d[v] + 1;
                    p[i] = v;
                    q.push(i);
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
