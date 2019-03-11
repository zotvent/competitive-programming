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
#include <climits>

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

const int inf = 1e9 + 5;
const int N = 1e4 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int n, k, s, x, res;
    vector<int> d;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n >> k >> s;
        for (int i = 0; i < s; i++) {
            cin >> x;
            d.pb(x);
        }
    }

    void prepare() {
    }

    void output() {
        cout << res;
    }

    void solution() {
        int position = 0;
        int leftKilometers = k;
        int i = 0;
        res = 0;

        for (int i = 0; i < s; i++) {
            int distance = d[i] - position;

            if (distance <= leftKilometers) {
                position = d[i];
                leftKilometers -= distance;
            }
            else {
                if (distance > k) {
                    res = -1;
                    break;
                }

                leftKilometers = k;
                res++;
                i--;
            }
        }

        if (res != -1 && n - position > leftKilometers && n - position <= k) {
            res++;
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
