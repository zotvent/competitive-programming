#include <bits/stdc++.h>

using namespace std;

int solve(int n, int p){
    // Complete this function
    return min(p/2, n/2 - p/2);
}

int main() {
    int n;
    cin >> n;
    int p;
    cin >> p;
    int result = solve(n, p);
    cout << result << endl;
    return 0;
}
