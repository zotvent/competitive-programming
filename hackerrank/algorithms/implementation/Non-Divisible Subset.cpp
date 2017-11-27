#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    vector<int> a(n), cnt(101, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]%k]++;
    }
    int res = 0;
    for (int i = 1; i <= (k-1)/2; i++)
        res += max(cnt[i], cnt[k-i]);
    if (cnt[0])
        res++;
    if (k%2 == 0 && cnt[k/2])
        res++;
    cout << res;
    return 0;
}
