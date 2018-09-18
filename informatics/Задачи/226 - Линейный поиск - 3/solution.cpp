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
const int N = 1005;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

int n, a[N], x;
vector<int> v;

void input() {
    speed
    cin >> n;
    for (int i = 1; i <= n; i++)
    	cin >> a[i];
    cin >> x;
}

void solve() {
    for (int i = 1; i <= n; i++)
        if (a[i] == x)
            v.pb(i);
}

void output() {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}

int main() {
    input();
    solve();
    output();
    return 0;
}
