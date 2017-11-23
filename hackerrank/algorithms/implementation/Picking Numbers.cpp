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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    int res = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
        if (i == 0 || a[i] != a[i-1])
            for (int j = i; j < a.size(); j++)
                if (a[j]-a[i] <= 1)
                    res = max(res, j-i+1);
    cout << res;
    return 0;
}
