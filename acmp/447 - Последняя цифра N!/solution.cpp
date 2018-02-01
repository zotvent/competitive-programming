#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstring>

using namespace std;

#define F first
#define S second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 15;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

ll n, res = 1, ost = 1000000;

void input() {
    cin >> n;
}

void solve() {
    for (ll i = 1; i <= n; i++) {
        res *= i;
        while (res%10 == 0) res /= 10;
        res %= ost;
    }
}

void output() {
    cout << res % 10;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
