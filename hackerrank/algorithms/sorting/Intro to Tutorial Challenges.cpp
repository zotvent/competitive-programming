#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, v, a;
    cin >> v >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == v) {
            cout << i;
            break;
        }
    }
    return 0;
}
