#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

#define For(i, start, end) for (int (i) = (start); (i) < (end); (i)++)
#define rof(i, start, end) for (int (i) = (start); (i) > (end); (i)--)
#define mp(i, j) make_pair (i, j)

using namespace std;

const int INF = 1000000000;

int n, p[100];
set<int> ans;

int main() {
    freopen("rootdist.in", "r", stdin);
    freopen("rootdist.out", "w", stdout);

    cin >> n;
    For(i, 0, n - 1) {
        int temp;
        cin >> temp;
        p[i + 1] = temp - 1;
    }

    p[0] = -1;
    int max = 0;
    For(j, 0, n - 1) {
        int temp = 0;
        for (int i = p[j + 1]; i != -1; i = p[i])
            temp++;
        if (temp > max) max = temp;
    }

    For(j, 0, n - 1) {
        int temp = 0;
        for (int i = p[j + 1]; i != -1; i = p[i])
            temp++;
        if (temp == max)
            ans.insert(j + 2);
    }

    if (max == 0) ans.insert(1);
    
    cout << max << "\n";
    cout << ans.size() << "\n";
    for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it)
        cout << *it << " ";


    return 0;
}