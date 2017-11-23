#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, res = 0, cur = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'U')
            cur++;
        else {
            if (cur == 0)
                res++;
            cur--;
        }
    }
    cout << res;
    return 0;
}
