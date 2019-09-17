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
const int N = 1e2 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int n;
    int a[N];

    void print() {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void prepare() {
    }

    void output() {
    }

    void solution() {
        int cnt = 0;
        int hole, value;

        for (int i = 0; i < n; i++) {
            hole = i;
            value = a[i];

            while (hole > 0 && value < a[hole - 1]) {
                a[hole] = a[hole - 1];
                --hole;
                cnt++;
            }

            a[hole] = value;
            if (cnt > 0) {
                print();
                cnt = 0;
            }
        }
    }

public:

    Solution() {
    }

    void solve() {
        prepare();
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
