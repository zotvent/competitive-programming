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
const int N = 55;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, s, t, d[N][N];
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> s >> t;
        prepare();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> d[i][j];
    }
    
    void prepare() {
    }
    
    void output() {
        cout << d[s][t];
    }
    
    void solution() {
        floyd();
    }

    void floyd() {
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (d[i][k] != -1 && d[k][j] != -1) {
                        if (d[i][j] == -1)
                            d[i][j] = d[i][k] + d[k][j];
                        else
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
    }
    
public:
    
    Solution() {
    }
    
    void solve() {
        input();
        solution();
        output();
    }
};

int main() {
    Solution s = Solution();
    s.solve();
    return 0;
}
