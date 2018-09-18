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
const int N = 1005;
const int mod = 16714589;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, a[N], dp[N], res;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void solve() {
    for (int i = 1; i <= n; i++)
        dp[i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            if (a[i] < a[j] && dp[j] < dp[i]+1)
                dp[j] = dp[i]+1;
}

void output() {
    res = dp[1];
    for (int i = 2; i <= n; i++)
        res = max(res, dp[i]);
    cout << res;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
