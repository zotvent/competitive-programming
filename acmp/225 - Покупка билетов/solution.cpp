#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
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
const int N = 5010;
const int mod = 16714589;
const int MAX = 2500;

using namespace std;

int n, a[N], b[N], c[N], dp[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1]+a[i];
        if (i > 1)
            dp[i] = min(dp[i], dp[i-2] + b[i-1]);
        if (i > 2)
            dp[i] = min(dp[i], dp[i-3] + c[i-2]);
    }

    cout << dp[n];

    return 0;
}
