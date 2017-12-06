#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
        if (isalpha(s[i])) {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = 'a' + (s[i]-'a'+k)%26;
            else
                s[i] = 'A' + (s[i]-'A'+k)%26;
        }
    cout << s;
    return 0;
}
