#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, a, b;
        cin >> n >> a >> b;
        set<int> s;
        for (int i = 0; i < n; i++)
            s.insert(a*i + b*(n-1-i));
        for (auto i: s)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
