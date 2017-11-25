#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    int cnt = 0, page = 1, problem = 0;
    for (int i = 0; i < n; i++) {
        problem = 0;
        while (t[i] > 0) {
            if (problem+1 <= page && page <= problem+min(k, t[i]))
                cnt++;
            problem += k;
            page++;
            t[i] -= k;
        }
    }
    cout << cnt;
    return 0;
}
