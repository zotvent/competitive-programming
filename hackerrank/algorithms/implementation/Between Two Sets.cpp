#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a/gcd(a, b) * b;
}

int gcd(vector<int> v) {
    int result = v[0];
    for (int i = 1; i < v.size(); i++)
        result = gcd(result, v[i]);
    return result;
}

int lcm(vector<int> v) {
    int result = v[0];
    for (int i = 1; i < v.size(); i++)
        result = lcm(result, v[i]);
    return result;
}


int getTotalX(vector <int> a, vector <int> b) {
    // Complete this function
    int lcm = ::lcm(a);
    int gcd = ::gcd(b);
    int cnt = 0;
    for (int i = lcm; i <= gcd; i += lcm)
        if (gcd%i == 0)
            cnt++;
    return cnt;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
