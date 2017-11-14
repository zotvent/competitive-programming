#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, a[1001], cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int j = i-1;
        while (j >= 0 && a[j+1] < a[j]) {
            swap(a[j+1], a[j]);
            j--;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
