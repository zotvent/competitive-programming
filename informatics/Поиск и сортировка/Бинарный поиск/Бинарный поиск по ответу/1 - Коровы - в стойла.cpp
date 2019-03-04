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
const int N = 1e4+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, k, a[N], i, res = 0;
    
    void print() {
    }
    
    void input() {
        speed
        //        freopen("input.txt", "r", stdin);
        //        freopen("output.txt", "w", stdout);
        cin >> n >> k;
        for (i = 1; i <= n; i++)
            cin >> a[i];
    }
    
    void output() {
        cout << res;
    }
    
    void solution() {
        int l = 0, r = a[n] - a[1];
        while (l <= r) {
            int m = (l + r) / 2;
            pii temp = calc(m);
            
            if (temp.F >= k && temp.S >= m) {
                res = temp.S;
                l = m + 1;
            }
            else
                r = m - 1;
        }
    }
    
    pii calc(int dif) {
        int cnt = 1, ans = inf, prev = 1;
        for (i = 2; i <= n; i++)
            if (a[i] - a[prev] >= dif) {
                cnt++;
                ans = min(ans, a[i] - a[prev]);
                prev = i;
            }
        return mp(cnt, ans);
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
