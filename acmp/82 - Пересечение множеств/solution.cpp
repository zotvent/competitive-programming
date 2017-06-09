#include <stdio.h>
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
 
const int inf = 1e9;
const int N = 1e5+5;
const int mod = 1e9+7;
const int MAX = 2500;
 
using namespace std;
 
int n, m, a[N], num;
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < N; i++) a[i] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);
        a[num] = 1;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &num);
        if (a[num] == 1) a[num] = 2;
    }
    for (int i = 0; i < N; i++)
        if (a[i] == 2) printf("%d ", i);
    return 0;
}