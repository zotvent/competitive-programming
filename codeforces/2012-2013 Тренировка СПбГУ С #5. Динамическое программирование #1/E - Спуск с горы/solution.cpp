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

const int INF = 1e9, MAXN = 105;

using namespace std;

int n, m, dp[MAXN][MAXN], a[MAXN][MAXN], ans = -INF;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++) dp[i][j] = -INF;

	dp[1][1] = a[1][1];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j];

	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[n][i]);

	cout << ans;
	
	return 0;
}