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

const ll inf = 1e9;
const int N = 1e5+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    int n, k;
    int a[N], b[N];
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) cin >> b[i];
    }
    
    void output() {
    }
    
    void solution() {
        for (int i = 1; i <= k; i++)
            cout << binary_search(b[i]) << endl;
    }

    int binary_search(int x) {
        int l = 1, r = n;
        int res;
        ll dif = 4 * inf + 5;

        while (l <= r && res != x) {
            int m = (l + r) / 2;
            
            if (x < a[m]) 
                r = m - 1;
            else if (x > a[m]) 
                l = m + 1;

            ll temp = abs(x - a[m]);
            if (temp < dif) {
                dif = temp;
                res = a[m];
            }
            else if (temp == dif) 
                res = min(res, a[m]);
        }

        return res;
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
