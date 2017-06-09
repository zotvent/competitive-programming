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

const int INF = 1e9, MAXN = 1e4+5;

using namespace std;

int n, dp[25][3];

int main() {
    cin >> n;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][1] + dp[i-1][2];
        dp[i][2] = dp[i][0];
    }

    if (n == 0) cout << 1;
    else cout << dp[n][0] + dp[n][1] + dp[n][2];

    return 0;
}