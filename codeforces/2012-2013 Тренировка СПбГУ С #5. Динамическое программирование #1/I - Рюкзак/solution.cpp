#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair

const int INF = 1e9, MAXN = 1e4+5;

using namespace std;

int s, n, a[305], dp[MAXN];

int main() {
    cin >> s >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = s-a[i]; j >= 0; j--)
            if (dp[j]) dp[j+a[i]] = 1;
    }

    for (int i = s; i >= 0; i--)
        if (dp[i]) {
            cout << i;
            break;
        }

    return 0;
}