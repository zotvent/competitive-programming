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
const int N = 1e5+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, k, a[N], b[N], i;
    
    void print() {
    }
    
    void input() {
        speed
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
        cin >> n >> k;
        for (i = 1; i <= n; i++)
            cin >> a[i];
        for (i = 1; i <= k; i++)
            cin >> b[i];
    }
    
    void output() {
    }
    
    void solution() {
        for (i = 1; i <= k; i++)
            binary_search(b[i]);
    }
    
    void binary_search(int num) {
        int l = 1, r = n;
        int dif = abs(num - a[1]), res = a[1];
        while(l <= r) {
            int m = (l + r) / 2;
            int cur_dif = abs(a[m] - num);
            
            if (cur_dif < dif) {
                dif = cur_dif;
                res = a[m];
            }
            else if (cur_dif == dif)
                res = min(res, a[m]);
            
            if (a[m] < num)
                l = m + 1;
            else
                r = m - 1;
        }
        cout << res << endl;
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
