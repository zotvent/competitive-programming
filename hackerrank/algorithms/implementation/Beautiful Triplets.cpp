#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int const N = 2*(int)1e4 + 1;
    int n, d;
    vector<int> a(N, 0);
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[temp] = 1;
    }
    int cnt = 0;
    for (int i = d; i < N-d; i++)
        if (a[i] && a[i-d] && a[i+d])
            cnt++;
    cout << cnt;
    return 0;
}
