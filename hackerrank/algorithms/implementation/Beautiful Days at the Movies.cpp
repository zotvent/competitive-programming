#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int n) {
    vector<int> v;
    while (n != 0) {
        v.push_back(n%10);
        n /= 10;
    }
    int res = 0, end = 0, k = 1;
    for (int i = 0; i < v.size(); i++)
        if (v[i] > 0) {
            end = i;
            break;
        }
    for (int i = v.size()-1; i >= end; i--) {
        res += k * v[i];
        k *= 10;
    }
    return res;
}

bool isBeautiful(int n, int k) {
    return abs(reverse(n)-n)%k == 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int from, to, k, cnt = 0;
    cin >> from >> to >> k;
    for (int i = from; i <= to; i++)
        if (isBeautiful(i, k))
            cnt++;
    cout << cnt;
    return 0;
}
