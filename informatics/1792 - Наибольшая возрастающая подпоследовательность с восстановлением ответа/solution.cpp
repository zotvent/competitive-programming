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

int n, a[N], dp[N], p[N], res, last;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        p[i] = -1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            if (a[i] < a[j]) {
                if (dp[j] < dp[i]+1) {
                    dp[j] = dp[i]+1;
                    p[j] = i;
                }
            }
}

void output() {
    res = dp[1];
    for (int i = 2; i <= n; i++)
        if (dp[i] > res) {
            res = dp[i];
            last = i;
        }

    vector<int> path;
    path.pb(a[last]);
    for (int i = p[last]; i != -1; i = p[i])
        path.pb(a[i]);
    for (int i = path.size()-1; i >= 0; i--)
        cout << path[i] << ' ';
}

int main() {
    input();
    solve();
    output();
    return 0;
}
