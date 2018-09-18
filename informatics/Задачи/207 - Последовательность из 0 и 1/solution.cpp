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

int n;
vector<int> dp[N][5];

vector<int> sum(int pos) {
    vector<int> s(N);
    int remainder = 0;
    for (int i = 0; i < N; i++) {
        s[i] = dp[pos][0][i] + dp[pos][1][i] + remainder;
        remainder = s[i]/10;
        s[i] %= 10;
    }
    return s;
}

int main() {
    speed
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i][0].resize(N);
        dp[i][1].resize(N);
    }

    dp[1][0][0] = dp[1][1][0] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = sum(i-1);
        dp[i][1] = dp[i-1][0];
    }

    vector<int> ans = sum(n);
    int start = N-1;
    for (int i = N-1; i >= 0; i--) {
        if (ans[i] > 0) {
            start = i;
            break;
        }
    }

    for (int i = start; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}