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

const int INF = 1e9, MAXN = 1e3+5;

using namespace std;

int n, a[MAXN], dp[MAXN];

int main() {
	freopen("lepus.in", "r", stdin);
	freopen("lepus.out", "w", stdout);

	cin >> n;
	for (int i = 6; i <= n+5; i++) {
		char c;
		cin >> c;
		if (c == '.') a[i] = 0;
		else if (c == 'w') a[i] = -INF-1;
		else a[i] = 1;
	}

	for (int i = 0; i < MAXN; i++)
		dp[i] = -INF;
	for (int i = 0; i < 6; i++) dp[i] = -INF - 1;
	dp[6] = a[6];
	for (int i = 7; i <= n + 5; i++) {
		if (a[i] != -INF - 1) {
			dp[i] = max(dp[i - 1], max(dp[i - 3], dp[i - 5])) + a[i];
		}
	}
	
	if (dp[n + 5] < 0) cout << -1;
	else cout << dp[n + 5];
	
	return 0;
}