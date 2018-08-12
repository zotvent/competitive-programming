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
    int n, r, c, i, res;
    vector<int> v;
    
    void print() {
    }
    
    void input() {
        speed
       // freopen("input.txt", "r", stdin);
       // freopen("output.txt", "w", stdout);
        cin >> n >> r >> c;
        v.resize(n);
        for (i = 0; i < n; i++)
            cin >> v[i];
    }
    
    void output() {
        cout << res;
    }
    
    void solution() {
        sort(v.begin(), v.end());
        
        int l = 0;
        int r = v[n-1] - v[0];

        while(l <= r) {
            int m = (l + r) / 2;
            int temp = calc(m);

            if (temp == -1)
                l = m + 1;
            else {
                res = temp;
                r = m - 1;
            }
        }
    }

    int calc(int m) {
        int start = 0, end = 0;
        vector<int> dif;

        while(start < n && end < n) {
            if (v[end] - v[start] <= m) {
                if (end - start + 1 == c) {
                    dif.pb(v[end] - v[start]);
                    end++;
                    start = end;
                } 
                else
                    end++;
            } else
                start++;
        }

        int ans = -1;
        if (dif.size() >= r) {
            sort(dif.begin(), dif.end());
            ans = dif[r - 1];
        }
        
        return ans;
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
