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
    int m, n, i, res = 0, groups = 0;
    pii deer[N], elf[N];
    
    void print() {
        cout << endl;
        cout << "DEERS:\n";
        for (i = 0; i < m; i++)
            printf("(%d, %d) ", deer[i].F, deer[i].S);
        cout << "\nELFS:\n";
        for (i = 0; i < n; i++)
            printf("(%d, %d) ", elf[i].F, elf[i].S);
        cout << endl;
    }
    
    void input() {
        speed
        //        freopen("input.txt", "r", stdin);
        //        freopen("output.txt", "w", stdout);
        cin >> m >> n;
        for (i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            deer[i] = mp(temp, i + 1);
        }
        for (i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            elf[i] = mp(temp, i + 1);
        }
    }
    
    void output() {
        cout << res << endl;
        calc(groups, true);
    }
    
    void solution() {
        sort(deer, deer + m);
        sort(elf, elf + n);
//        print();
        int l = 0, r = min(m, n / 2);
        while(l <= r) {
            int k = (l + r) / 2;
            int temp = calc(k);
            
            if (temp > res) {
                res = temp;
                groups = k;
            }
            
            if (temp >= k)
                l = k + 1;
            else
                r = k - 1;
        }
    }
    
    int calc(int k, bool print = false) {
        int start = 0, cnt = 0, end = 0;
        for (i = 0; i < m; i++) {
            end = n - k + start;
            if (elf[start].F < deer[i].F && deer[i].F < elf[end].F) {
                if (print)
                    printf("%d %d %d\n", deer[i].S, elf[start].S, elf[end].S);
                start++;
                cnt++;
            }
        }
        return cnt;
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
