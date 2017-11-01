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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 1e9;
const int N = 10005;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, m, k, u, v, c, path[100005], last = 1, g[N][105];
bool isCorrect = true;

void input() {
    speed
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> c;
        g[u][c] = v;
        g[v][c] = u;
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> path[i];
}

void solve() {
    for (int i = 1; i <= k; i++) {
        int room = g[last][path[i]];
        if (room == 0) {
            isCorrect = false;
            break;
        }
        last = room;
    }
}

void output() {
    if (isCorrect)
        cout << last;
    else
        cout << "INCORRECT";
}

int main() {
    input();
    solve();
    output();
    return 0;
}