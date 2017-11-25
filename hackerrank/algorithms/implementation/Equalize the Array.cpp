#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> a(n), cnt(101, 0);
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        max = ::max(max, cnt[a[i]]);
    }
    cout << n-max;
    return 0;
}
