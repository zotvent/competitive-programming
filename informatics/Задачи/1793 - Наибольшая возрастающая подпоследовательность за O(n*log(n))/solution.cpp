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
const int N = 100005;
const int mod = 16714589;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, k, b, m, a[N];
vector<int> dp(N);

void input() {
    cin >> n >> a[1] >> k >> b >> m;
    for (int i = 2; i <= n; i++)
        a[i] = (k*a[i-1] + b) % m;
}

void solve() {
    dp[0] = -inf;
    for (int i = 1; i <= N; i++)
        dp[i] = inf;
    for (int i = 1; i <= n; i++) {
        int j = int (upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin());
        if (dp[j-1] < a[i] && a[i] < dp[j])
            dp[j] = a[i];
    }
}

void output() {
    for (int i = n; i > 0; i--)
        if (dp[i] != inf) {
            cout << i;
            break;
        }
}

int main() {
    input();
    solve();
    output();
    return 0;
}
