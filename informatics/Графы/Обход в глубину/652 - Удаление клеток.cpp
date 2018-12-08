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
    int n, m, cnt;
    vector<int> dx, dy;
    char g[N][N];
    vector< vector<int> > used;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> m;
        used.assign(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> g[i][j];
    }
    
    void output() {
        cout << cnt;
    }
    
    void solution() {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!used[i][j] && g[i][j] == '#') {
                    dfs(i, j);
                    cnt++;
                }
    }

    void dfs(int x, int y) {
        used[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int row = x + dx[i];
            int col = y + dy[i];

            if (valid(row, col)) {
                if (!used[row][col] && g[row][col] == '#')
                    dfs(row, col);
            }
        }
    }

    bool valid(int x, int y) {
        return x > 0 && y > 0 && x <= n && y <= m;
    }
    
public:

    Solution() {
        cnt = 0;
        int x[] = {1, -1, 0, 0};
        int y[] = {0, 0, 1, -1};

        dx.assign(x, x + 4);
        dy.assign(y, y + 4);
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
