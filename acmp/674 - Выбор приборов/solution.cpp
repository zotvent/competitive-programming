#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const ll inf = 1e18;
const int N = 105;
const int mod = 1e9+7;
const int MAX = 2500;

using namespace std;

int n;

int calc(int x) {
    if (x < 3) return 0;
    if (x == 3) return 1;
    if (x%2 == 0) return 2 * calc(x/2);
    else return calc(x/2) + calc(x/2+1);
}

int main() {
    speed
    cin >> n;
    cout << calc(n);
    return 0;
}