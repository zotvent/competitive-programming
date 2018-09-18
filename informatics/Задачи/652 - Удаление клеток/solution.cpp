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
    int n, m, used[N][N], color[N], res = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    char g[N][N];
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];
    }
    
    bool valid(int x, int y) {
        return x > 0 && x <= m && y > 0 && y <= n;
    }
    
    void output() {
        cout << res;
    }
    
    void dfs(int row, int col) {
        used[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];
            if (valid(x, y) && !used[x][y] && g[x][y] == '#')
                dfs(x, y);
        }
    }
    
    void solution() {
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][j] == '#' && !used[i][j]) {
                    dfs(i, j);
                    res++;
                }
    }
    
public:
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
