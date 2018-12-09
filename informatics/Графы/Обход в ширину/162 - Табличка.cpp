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
const int N = 505;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, m, g[N][N];
    vector<int> dx, dy;
    vector< vector<int> > d;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> m;
        prepare();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
                if (g[i][j])
                    d[i][j] = 0;
            }
        }
    }

    void prepare() {
        d.assign(n + 1, vector<int>(m + 1, inf));

        int x[] = {1, -1, 0, 0};
        int y[] = {0, 0, 1, -1};

        dx.assign(x, x + 4);
        dy.assign(y, y + 4);
    }
    
    void output() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                cout << d[i][j] << ' ';
            cout << endl;
        }
    }
    
    void solution() {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!d[i][j])
                    bfs(mp(i, j));
    }

    void bfs(pii s) {
        queue<pii> q;
        q.push(s);

        while (!q.empty()) {
            pii v = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = v.F + dx[i];
                int y = v.S + dy[i];

                if (valid(x, y)) {
                    int dist = abs(dx[i]) + abs(dy[i]) + d[v.F][v.S];
                    if (d[x][y] > dist) {
                        d[x][y] = dist;
                        q.push(mp(x, y));
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
