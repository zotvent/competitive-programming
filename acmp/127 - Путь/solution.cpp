#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 1e9;
const int N = 105;
const int mod = 1e9+7;
const int MAX = 2500;

using namespace std;

int n, g[N][N], dp[N], s, e, used[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    used[s] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (g[v][i] && !used[i]) {
                used[i] = 1;
                dp[i] = dp[v]+1;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    cin >> s >> e;
    bfs(s);
    cout << (used[e] ? dp[e] : -1);
    return 0;
}