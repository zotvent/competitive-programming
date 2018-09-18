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
const int N = 20;
const int mod = 16714589;
const int MAX = 2500;

using namespace std;

int n, m, dp[N][N];

void rec(int i, int j) {
    if (i == n && j == m)
        return;

    if (i+2 <= n && j+1 <= m) {
        dp[i+2][j+1] += dp[i][j];
        rec(i+2, j+1);
    }
    if (i+1 <= n && j+2 <= m) {
        dp[i+1][j+2] += dp[i][j];
        rec(i+1, j+2);
    }
    if (i+2 <= n && j > 1) {
        dp[i+2][j-1] += dp[i][j];
        rec(i+2, j-1);
    }
    if (i > 1 && j+2 <= m) {
        dp[i-1][j+2] += dp[i][j];
        rec(i-1, j+2);
    }

    dp[i][j] = 0;
}

int main() {
    cin >> n >> m;
    dp[1][1] = 1;
    rec(1, 1);
    cout << dp[n][m];
    return 0;
}
