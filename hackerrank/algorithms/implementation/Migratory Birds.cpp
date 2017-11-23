#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    // Complete this function
    vector<int> frequency(5);
    for (int i = 0; i < ar.size(); i++)
        frequency[ar[i]-1]++;
    int max = 0, res = 0;
    for (int i = 4; i >= 0; i--)
        if (frequency[i] >= max) {
            max = frequency[i];
            res = i+1;
        }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}
