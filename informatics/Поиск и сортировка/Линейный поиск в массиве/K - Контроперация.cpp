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
const int N = 1e2+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, i, a[N], imin = 1, imax = 1;
    
    void print() {
    }
    
    void input() {
        speed
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
        cin >> n;
        for (i = 1; i <= n; i++)
            cin >> a[i];
    }
    
    void output() {
        for (i = 1; i <= n; i++)
            if (a[i] == a[imax]) cout << a[imin] << ' ';
            else cout << a[i] << ' ';
    }
    
    void solution() {
        for (i = 1; i <= n; i++) {
            if (a[i] > a[imax]) imax = i;
            if (a[i] < a[imin]) imin = i;
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
