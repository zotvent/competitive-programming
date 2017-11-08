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
    long int a;
    long int b;
    long int c;
    long int d;
    long int e;
    cin >> a >> b >> c >> d >> e;
    long int arr[5];
    arr[0] = a+b+c+d;
    arr[1] = a+c+d+e;
    arr[2] = a+b+d+e;
    arr[3] = a+b+c+e;
    arr[4] = b+c+d+e;
    long int q = arr[0], w = arr[0];
    for (int i = 0; i < 5; i++) {
        q = min(q, arr[i]);
        w = max(w, arr[i]);
    }
    cout << q << " " << w;
    return 0;
}
