#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair

const int INF = 1e9, MAXN = 55;

using namespace std;

int n, m, dp[MAXN][MAXN];

int main() {
	freopen("knight.in", "r", stdin);
	freopen("knight.out", "w", stdout);

	cin >> n >> m;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] += dp[i - 2][j - 1] + dp[i - 1][j - 2];
		}
	}

	cout << dp[n][m];
	
	return 0;
}