#include <bits/stdc++.h>

using namespace std;

int sockMerchant(int n, vector <int> ar) {
    // Complete this function
    int res = 0;
    map<int, int> dict;
    for (int i = 0; i < ar.size(); i++)
        if (dict[ar[i]] == 1) {
            dict[ar[i]] = 0;
            res++;
        }
        else
            dict[ar[i]]++;
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = sockMerchant(n, ar);
    cout << result << endl;
    return 0;
}
