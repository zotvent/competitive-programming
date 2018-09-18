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
const int N = 1e5+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, m, used[N];
    vector<int> g[N], path;
    vector<vector<int>> paths;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int from, to;
            cin >> from >> to;
            g[from].pb(to);
            g[to].pb(from);
        }
    }
    
    void output() {
        cout << paths.size() << endl;
        for (int i = 0; i < paths.size(); i++) {
            cout << paths[i].size() << endl;
            for (int j = 0; j < paths[i].size(); j++)
                cout << paths[i][j] << ' ';
            cout << endl;
        }
    }
    
    void dfs(int v) {
        used[v] = 1;
        path.pb(v);
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (!used[to])
                dfs(to);
        }
    }
    
    void solution() {
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                path.clear();
                dfs(i);
                paths.pb(path);
            }
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
