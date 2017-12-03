#include <bits/stdc++.h>

using namespace std;

int a[100][100];

void tripleRecursion(int n, int m, int k) {
    // Complete this function
    a[0][0] = m;
    for (int i = 1; i < n; i++)
        a[i][i] = a[i-1][i-1]+k;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            a[i][j] = a[i][j-1]-1;
            a[j][i] = a[j-1][i]-1;
        }
}

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    tripleRecursion(n, m, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
