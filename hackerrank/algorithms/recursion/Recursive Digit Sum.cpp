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

int superDigit(string n, int k) {
    // Complete this function    
    if (k == 1 && n.length() == 1)
        return n[0]-'0';
    
    int sum = 0;
    for (int i = 0; i < n.length(); i++)
        sum += (n[i]-'0');
    
    int res = superDigit(to_string(sum), 1);
    res *= k;
    
    return (res < 10 ? res : superDigit(to_string(res), 1));
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    int result = superDigit(n, k);
    cout << result << endl;
    return 0;
}
