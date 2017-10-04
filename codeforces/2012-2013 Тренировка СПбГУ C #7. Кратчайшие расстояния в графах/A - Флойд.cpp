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

const int inf = 1e18;
const int N = 105;
const int mod = 1e9+7;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, dp[N][N];

void input() {
    speed
    freopen("floyd.in", "r", stdin);
    freopen("floyd.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dp[i][j];
}

void solve() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
}

void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    
}

int main() {
    input();
    solve();
    output();
    return 0;
}
