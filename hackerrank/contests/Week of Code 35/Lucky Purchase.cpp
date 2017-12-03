#include <bits/stdc++.h>

using namespace std;

string brand;
int max_value = (int)1e9 + 5;

void check(string name, int value) {
    int fours = 0, sevens = 0, price = value;
    while (price > 0) {
        int last = price%10;
        if (last == 4)
            fours++;
        else if (last == 7)
            sevens++;
        else
            return;
        price /= 10;
    }
    if (fours == sevens && value < max_value) {
        max_value = value;
        brand = name;
    }
}

int main() {
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string name;
        int value;
        cin >> name >> value;
        check(name, value);
    }
    if (brand.length() > 0)
        cout << brand;
    else
        cout << -1;
    return 0;
}
