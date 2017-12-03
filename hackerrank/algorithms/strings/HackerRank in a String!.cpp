#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    string hackerrank = "hackerrank";
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        // your code goes here
        int j = 0;
        for (int i = 0; i < s.length(); i++) 
            if (j < hackerrank.length() && s[i] == hackerrank[j])
                j++;
        cout << (j == hackerrank.length() ? "YES" : "NO") << endl;
    }
    return 0;
}
