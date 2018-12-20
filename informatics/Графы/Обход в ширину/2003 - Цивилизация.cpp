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
const int N = 1e3+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, m;
    char g[N][N];
    pii s, e;
    vector<int> dx, dy;
    vector< vector<int> > d;
    vector< vector<pii> > p;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> m;
        
        int x, y;
        cin >> x >> y;
        s = mp(x, y);

        cin >> x >> y;
        e = mp(x, y);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> g[i][j];

        prepare();
    }
    
    void prepare() {
        d.assign(N, vector<int>(N, inf));
        p.assign(N, vector<pii>(N, mp(-1, -1)));
        
        int x[] = {0, 0, 1, -1};
        dx.assign(x, x + 4);
        
        int y[] = {1, -1, 0, 0};
        dy.assign(y, y + 4);
    }
    
    void output() {
        if (d[e.F][e.S] < inf) {
            cout << d[e.F][e.S] << endl;
            
            vector<pii> path;
            path.pb(e);
            for (pii i = p[e.F][e.S]; i != mp(-1, -1); i = p[i.F][i.S])
                path.pb(i);
            reverse(path.begin(), path.end());
            
            for (int i = 1; i < path.size(); i++) {
                int x = path[i].F - path[i - 1].F;
                int y = path[i].S - path[i - 1].S;

                if (x == 0 && y == 1) cout << 'E';
                if (x == 0 && y == -1) cout << 'W';
                if (x == 1 && y == 0) cout << 'S';
                if (x == -1 && y == 0) cout << 'N';
            }
        }
        else cout << -1;
    }
    
    void solution() {
        bfs();
    }
    
    void bfs() {
        queue<pii> q;
        q.push(s);
        d[s.F][s.S] = 0;
        
        while (!q.empty()) {
            pii v = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int x = v.F + dx[i];
                int y = v.S + dy[i];
                
                if (valid(x, y)) {
                    if (g[x][y] != '#') {
                        int dist = d[v.F][v.S] + (g[x][y] == '.' ? 1 : 2);
                        if (dist < d[x][y]) {
                            p[x][y] = v;
                            d[x][y] = dist;
                            q.push(mp(x, y));
                        }
                    }
                }
            }
        }
    }
    
    bool valid(int x, int y) {
        return x > 0 && y > 0 && x <= n && y <= m;
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
