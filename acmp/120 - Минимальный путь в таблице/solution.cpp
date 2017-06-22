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
const int N = 25;
const int mod = 1e9+7;
const int MAX = 1e4;

using namespace std;

int n, m, a[N][N], dp[N][N];

int main() {
    speed
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            dp[i][j] = inf;
        }
    dp[1][1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+a[i][j]);
            dp[i][j+1] = min(dp[i][j+1], dp[i][j]+a[i][j]);
        }
    cout << dp[n][m]+a[n][m];
    return 0;
}