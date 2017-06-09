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

const int INF = 1e9, MAXN = 1e4*5;

using namespace std;

int n, a[105], dp[105];

int main() {
	freopen("ladder.in", "r", stdin);
	freopen("ladder.out", "w", stdout);

	cin >> n;
	for (int i = 2; i <= n+1; i++) 
		cin >> a[i];

	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= n + 1; i++)
		dp[i] = max(dp[i - 1], dp[i - 2]) + a[i];
	
	cout << dp[n+1];
	
	return 0;
}