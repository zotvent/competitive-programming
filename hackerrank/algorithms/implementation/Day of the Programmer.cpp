#include <bits/stdc++.h>

using namespace std;

string dateString(int day, int month, int year) {
    string res = "";
    if (day < 10)
        res += "0";
    res += to_string(day);
    res += ".";
    if (month < 10)
        res += "0";
    res += to_string(month);
    res += ".";
    res += to_string(year);
    return res;
}

string calc(int days_in_month[], int year) {
    int i = 1, cur = 256;
    while (cur - days_in_month[i] > 0) {
        cur -= days_in_month[i++];
    }
    return dateString(cur, i, year);
}

string solve(int year){
    // Complete this function
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year <= 1917 && year%4 == 0)
            days_in_month[2]++;    
    else if (year == 1918) 
        days_in_month[2] = 15;
    else if (year > 1918 && (year%400 == 0 || (year%4 == 0 && year%100 != 0)))
            days_in_month[2]++;
    
    return calc(days_in_month, year);
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}
