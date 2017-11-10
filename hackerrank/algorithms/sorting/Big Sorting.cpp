#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b) {
    int n = a.length();
    int m = b.length();
    if (n == m)
        return a < b;
    return n < m;
}

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    // your code goes here
    sort(unsorted.begin(), unsorted.end(), comp);
    for (int i = 0; i < unsorted.size(); i++)
        cout << unsorted[i] << endl;
    return 0;
}
