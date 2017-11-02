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
const int N = 105;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int n, m, start;
vector<string> g[N];
map<string, int> stringToInt;
vector<int> used;
vector<bool> res(N, false);

void input() {
    speed
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string key1;
        cin >> key1 >> m;
        stringToInt[key1] = i;
        for (int j = 1; j <= m; j++) {
            string key2;
            cin >> key2;
            g[i].pb(key2);
        }
        cin >> key1;
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    used.assign(N, 0);
    used[s] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            int index = stringToInt[g[v][i]];
            if (!used[index]) {
                q.push(index);
                used[index] = 1;
            }
            else {
                if (index == start) {
                    res[index] = true;
                    return;
                }
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        start = i;
        bfs(start);
    }
}

void output() {
    for (int i = 1; i <= n; i++)
        cout << (res[i] ? "YES" : "NO") << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}