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
const int N = 1e5 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int n, a[N];

    void print() {
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
        for (int i = 0; i < n; i++) {
          cout << a[i] << ' ';
        }
    }

    void solution() {
      quick_sort(0, n - 1);
    }

    void quick_sort(int start, int end) {
      if (start < end) {
        int m = random_partition(start, end);
        quick_sort(start, m - 1);
        quick_sort(m + 1, end);
      }
    }

    int random_partition(int start, int end) {
      int pivot = start + rand() % (end - start + 1);
      swap(a[end], a[pivot]);
      return partition(start, end);
    }

    int partition(int start, int end) {
      int pivot = end;
      int index = start;

      for (int i = start; i < end; i++) {
        if (a[i] < a[pivot]) {
          swap(a[i], a[index]);
          index++;
        }
      }
      swap(a[pivot], a[index]);

      return index;
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
