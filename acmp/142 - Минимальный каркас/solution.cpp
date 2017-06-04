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
const int N = 1e5+5;
const int mod = 1e9+7;
const int MAX = 2500;

using namespace std;

pair<int, pii> g[6006];
int n, m, ans = 0, tree_id[6006];

int main() {
    speed
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int from, to, len;
        cin >> from >> to >> len;
        g[i] = mp(len, mp(from, to));
    }

    sort(g, g+m+1);
    for (int i = 1; i <= n; i++)
        tree_id[i] = i;
    for (int i = 1; i <= m; i++) {
        int from = g[i].S.F, to = g[i].S.S, len = g[i].F;
        if (tree_id[from] != tree_id[to]) {
            ans += len;
            int old_id = tree_id[to], new_id = tree_id[from];
            for (int j = 1; j <= n; j++)
                if (tree_id[j] == old_id)
                    tree_id[j] = new_id;
        }
    }

    cout << ans;

    return 0;
}