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
    int const inf = (int) 1e9;
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for(int i = 0;i < n;i++){
       cin >> A[i].first;
       A[i].second = i;
    }
    sort(A.begin(), A.end());
    int res = inf;
    for (int i = 1; i < A.size(); i++)
        if (A[i].first == A[i-1].first)
            res = min(res, abs(A[i].second - A[i-1].second));
    cout << (res == inf ? -1 : res);
    return 0;
}
