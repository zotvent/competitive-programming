#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
    int cnt = 0;
    for (int i, j; i < s.length(), j < t.length(); i++, j++)
        if (s[i] != t[j])
            break;
        else
            cnt++;
    int need = s.length()+t.length()-2*cnt;
    if (k >= need && (k-need)%2 == 0 || k >= s.length()+t.length())
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
