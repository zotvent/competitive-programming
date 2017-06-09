#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
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
const int N = 105;
const int mod = 1e9+7;
const int MAX = 2500;

using namespace std;

int n, k, dp[20][2];

int main() {
    speed
    cin >> n >> k;
    dp[1][1] = k-1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]) * (k-1);
    }
    cout << dp[n][0] + dp[n][1];
    return 0;
}