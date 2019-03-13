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
const int N = 1e2 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int n;
    vector<int> dp[N][2], res;

    void print() {
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
    }

    void prepare() {
    }

    void output() {
        bool found = false;

        for (int i = N - 1; i >= 0; i--) {
            if (found) {
                cout << res[i];
            }
            else if (!found && res[i] > 0) {
                cout << res[i];
                found = true;
            }
        }
    }

    void solution() {
        for (int i = 1; i <= n; i++) {
            dp[i][0].resize(N);
            dp[i][1].resize(N);
        }

        dp[1][0][0] = dp[1][1][0] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i][0] = sum(i - 1);
            dp[i][1] = dp[i - 1][0];
        }

        res = sum(n);
    }

    vector<int> sum(int pos) {
        vector<int> res(N);
        int remainder = 0;

        for (int i = 0; i < N; i++) {
            res[i] = dp[pos][0][i] + dp[pos][1][i] + remainder;
            remainder = res[i] / 10;
            res[i] %= 10;
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
