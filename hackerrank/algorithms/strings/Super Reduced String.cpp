#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s){
    // Complete this function
    bool found;
    int j = 0;
    while (true) {
        found = false;
        for (int i = 1; i < s.length(); i++)
            if (s[i] == s[i-1]) {
                found = true;
                j = i-1;
                break;
            }
        if (!found)
            break;
        s = s.substr(0, j) + s.substr(j+2);
    }
    return (s.empty() ? "Empty String" : s);
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
