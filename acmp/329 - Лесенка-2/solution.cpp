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

using namespace std;

int n, a[N], p[N], dp[N];
vector<int> path;

int calc(int from, int to) {
    if (dp[to] < dp[from]+a[to]) {
        dp[to] = dp[from]+a[to];
        p[to] = from;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) dp[i] = -inf;

    for (int i = 0; i <= n; i++) {
        calc(i, i+1);
        calc(i, i+2);
    }

    p[0] = -1;
    for (int i = n; i != -1; i = p[i]) path.pb(i);

    cout << dp[n] << endl;
    for (int i = path.size()-2; i >= 0; i--)
        cout << path[i] << ' ';

    return 0;
}
