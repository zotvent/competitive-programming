#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isKaprekar(long x) {
    long square = x*x, cnt = 0;
    while (square != 0) {
        cnt++;
        square /= 10;
    }
    square = x*x;
    long left = square/((long) pow(10, (cnt+1)/2));
    long right = square%((long) pow(10, (cnt+1)/2));
    return x == left+right;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long p, q;
    vector<long> res;
    cin >> p >> q;
    for (long i = p; i <= q; i++)
        if (isKaprekar(i))
            res.push_back(i);
    if (res.size() == 0)
        cout << "INVALID RANGE";
    else
        for (long i = 0; i < res.size(); i++)
            cout << res[i] << ' ';
    return 0;
}
