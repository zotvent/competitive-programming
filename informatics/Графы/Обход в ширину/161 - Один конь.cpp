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
    int n;
    pii s, e;
    vector<int> dx, dy;
    vector< vector<int> > used, d;
    vector< vector<pii> > p;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
        cin >> s.F >> s.S;
        cin >> e.F >> e.S;
        prepare();
    }

    void prepare() {
        used.assign(n + 1, vector<int>(n + 1, 0));
        d.assign(n + 1, vector<int>(n + 1, inf));
        p.assign(n + 1, vector<pii>(n + 1, mp(-1, -1)));

        int x[] = {1, 1, -1, -1, 2, -2, 2, -2};
        int y[] = {2, -2, 2, -2, 1, 1, -1, -1};

        dx.assign(x, x + 8);
        dy.assign(y, y + 8);
    }
    
    void output() {
        vector<pii> path;
        path.pb(e);
        for (pii i = p[e.F][e.S]; i != mp(-1, -1); i = p[i.F][i.S])
            path.pb(i);

        reverse(path.begin(), path.end());
        cout << path.size() - 1 << endl;
        for (int i = 0; i < path.size(); i++)
            cout << path[i].F << ' ' << path[i].S << endl;
    }
    
    void solution() {
        bfs();
    }

    void bfs() {
        queue<pii> q;
        q.push(s);
        d[s.F][s.S] = 0;
        used[s.F][s.S] = 1;

        while (!q.empty()) {
            pii v = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                int x = v.F + dx[i];
                int y = v.S + dy[i];

                if (valid(x, y)) {
                    if (!used[x][y]) {
                        used[x][y] = 1;
                        p[x][y] = v;
                        d[x][y] = d[v.F][v.S] + 1;
                        q.push(mp(x, y));
                    }
                }
            }
        }
    }

    bool valid(int x, int y) {
        return x > 0 && y > 0 && x <= n && y <= n;
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
