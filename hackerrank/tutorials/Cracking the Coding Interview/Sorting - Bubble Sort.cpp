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

int buble_sort(vector<int> &v) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        int swaps = 0;
        for (int j = 0; j < v.size()-1; j++)
            if (v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
                swaps++;
            }
        res += swaps;
        if (swaps == 0)
            break;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    int cnt = buble_sort(a);
    printf("Array is sorted in %d swaps.\n", cnt);
    printf("First Element: %d\n", a[0]);
    printf("Last Element: %d", a[n-1]);
    return 0;
}
