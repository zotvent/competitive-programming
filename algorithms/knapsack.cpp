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
const int N = 10005;
const int mod = 16714589;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, x[105], s, dp[N];

void input() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
}

void solve() {
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        // for (int j = 0; j <= s-x[i]; j++) // unlimited number of each item
        for (int j = s-x[i]; j >= 0; j--) // limited number of each item
            if (dp[j])
                dp[j+x[i]] = 1;
}

void output() {
    cout << (dp[s] ? "YES" : "NO");
}

int main() {
    input();
    solve();
    output();
    return 0;
}
