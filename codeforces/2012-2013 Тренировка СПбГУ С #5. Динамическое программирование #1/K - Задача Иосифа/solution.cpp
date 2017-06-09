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
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int INF = 1e9, MAXN = 1e6+5;

using namespace std;

int n, p, d[MAXN];

int main() {
    freopen("joseph.in", "r", stdin);
    freopen("joseph.out", "w", stdout);
    speed
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        d[i] = (d[i-1]+p)%i;
    cout << d[n]+1;

    return 0;
}