#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s;
    cin >> s;
    string without_spaces;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            without_spaces.push_back(s[i]);
    
    int n = without_spaces.length();
    int row = round(sqrt(n)), col = 0;
    if (row >= sqrt(n))
        col = row;
    else
        col = row+1;
    
    for (int i = 0; i < col; i++) {
        for (int j = i; j < n; j += col)
            cout << without_spaces[j];
        cout << ' ';
    }
    
    return 0;
}


