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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 1e9;
const int N = 4e6+5;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, m;
vector<vector<int>> a, dp;
vector<int> msl, msr, d;

void input() {
    speed
    cin >> n >> m;
    
    msl.assign(m+2, 0);
    d = msr = msl;
    
    a.assign(n+2, d);
    dp = a;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            msl[j] = max(msl[j-1]+a[i][j], 0);
        for (int j = m; 0 < j; j--)
            msr[j] = max(msr[j+1]+a[i][j], 0);
        
        d[1] = dp[i-1][1]+a[i][1];
        dp[i][1] = d[1]+msr[2];
        for (int j = 2; j <= m; j++) {
            d[j] = max(d[j-1]+a[i][j], dp[i-1][j]+msl[j-1]+a[i][j]);
            dp[i][j] = d[j]+msr[j+1];
        }
        
        d[m] = dp[i-1][m]+a[i][m];
        dp[i][m] = max(dp[i][m], d[m]+msl[m-1]);
        for (int j = m-1; 0 < j; j--) {
            d[j] = max(d[j+1]+a[i][j], dp[i-1][j]+msr[j+1]+a[i][j]);
            dp[i][j] = max(dp[i][j], d[j]+msl[j-1]);
        }
    }
}

void output() {
    int res = dp[n][1];
    for (int i = 2; i <= m; i++)
        res = max(res, dp[n][i]);
    cout << res;
}

int main() {
    input();
    solve();
    output();
    return 0;
}