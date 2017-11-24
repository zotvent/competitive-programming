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
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> p(n+1);
    map<int, int> dict;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        dict[p[i]] = i;
    }
    for (int x = 1; x <= n; x++)
        cout << dict[dict[x]] << endl;
    return 0;
}
