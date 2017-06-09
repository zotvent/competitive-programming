#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
 
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>
 
const int inf = 2e9;
const int N = 1000;
const int M = 305;
const int mod = 1e9+7;
 
using namespace std;
 
int n, k;
vector<int> dp[N];
 
void add(int a, int b) {
    int remainder = 0, temp = 0;
    for (int i = 0; i < M; i++) {
        temp = dp[a][i] + dp[b][i] + remainder;
        dp[a][i] = temp%10;
        remainder = temp/10;
    }
}
 
int main() {
    speed
    cin >> k >> n;
    for (int i = 0; i <= n+k; i++) {
        dp[i].resize(M);
        for (int j = 0; j < M; j++)
            dp[i][j] = 0;
    }
    dp[0][0] = 1;
 
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= k; j++)
            add(i+j, i);
 
    int s = 0;
    for (int i = M-1; i >= 0; i--)
        if (dp[n][i]) {
            s = i;
            break;
        }
    for (int i = s; i >= 0; i--)
        cout << dp[n][i];
 
    return 0;
}