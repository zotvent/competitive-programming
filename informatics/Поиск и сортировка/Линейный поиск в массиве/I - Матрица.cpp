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
const int N = 755;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, m, k[N][N], row[N], col[N], i, j, res = 0;
    
    void print() {
    }
    
    void input() {
        speed
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
        cin >> n >> m;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                cin >> k[i][j];
    }
    
    void output() {
        cout << res;
    }
    
    void solution() {
        min_in_row();
        max_in_col();
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                if (row[i] == col[j])
                    res++;
    }
    
    void min_in_row() {
        for (i = 1; i <= n; i++) {
            int jmin = 1;
            for (j = 1; j <= m; j++)
                if (k[i][j] < k[i][jmin])
                    jmin = j;
            row[i] = k[i][jmin];
        }
    }
    
    void max_in_col() {
        for (j = 1; j <= m; j++) {
            int imax = 1;
            for (i = 1; i <= n; i++)
                if (k[i][j] > k[imax][j])
                    imax = i;
            col[j] = k[imax][j];
        }
    }
    
public:
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
