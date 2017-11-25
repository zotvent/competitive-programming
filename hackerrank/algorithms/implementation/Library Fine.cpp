#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dateInDays(int day, int month, int year) {
    return day + month*30 + year*365;
}

int main(){
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;
    int returnedDate = dateInDays(d1, m1, y1);
    int expectedDate = dateInDays(d2, m2, y2);
    if (returnedDate <= expectedDate)
        cout << 0;
    else if (d1 > d2 && m1 == m2 && y1 == y2)
        cout << 15*(d1-d2);
    else if (m1 > m2 && y1 == y2)
        cout << 500*(m1-m2);
    else
        cout << 10000;
    return 0;
}
