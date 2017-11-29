#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string int_to_string(int n) {
    vector<string> numbers = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "quarter",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine",
        "half"
    };
    return numbers[n];
}

string minutesToString(int m) {
    string res = int_to_string(m);
    if (m == 1)
        res += " minute";
    else if (m != 15 && m != 30)
        res += " minutes";
    return res;
}

string timeToString(int h, int m) {
    if (m == 0)
        return int_to_string(h) + " o' clock";
    else if (m <= 30)
        return minutesToString(m) + " past " + int_to_string(h);
    else {
        string next_hour = (h < 11 ? int_to_string(h+1) : int_to_string(1)); 
        return minutesToString(60-m) + " to " + next_hour;
    }
}

int main(){
    int h, m;
    cin >> h >> m;
    cout << timeToString(h, m);
    return 0;
}
