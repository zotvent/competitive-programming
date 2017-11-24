#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, cnt = 0, cur = 5;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cnt += floor(cur/2);
        cur = floor(cur/2) * 3;
    }
    cout << cnt;
    return 0;
}
