#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, a, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        int cnt = 0;
        int j = ceil(sqrt(a));
        for (; j*j <= b; j++)
            cnt++;
        cout << cnt << endl;
    }
    return 0;
}
