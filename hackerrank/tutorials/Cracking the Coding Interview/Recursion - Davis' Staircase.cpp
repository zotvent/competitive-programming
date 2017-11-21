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

vector<int> calculated(40, 0);
vector<int> d(40);

int calc(int n) {
    if (n >= 0) {
        if (calculated[n])
            return d[n];
        else {
            if (n == 0 || n == 1) {
                calculated[n] = 1;
                d[n] = 1;
                return d[n];
            }
            else {
                int res = calc(n-1) + calc(n-2) + calc(n-3);
                calculated[n] = 1;
                d[n] = res;
                return d[n];
            }
        }
    }
    else
        return 0;
}

int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        cout << calc(n) << endl;
    }
    return 0;
}
