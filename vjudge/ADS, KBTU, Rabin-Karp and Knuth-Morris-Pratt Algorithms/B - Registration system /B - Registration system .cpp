#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstring>

using namespace std;

#define F first
#define S second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 1e5+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;
const int p = 31;

class Solution {
    int n;
    unordered_map<string, int> db;
    string name;
    
    void print() {
    }
    
    void input() {
        speed
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
        cin >> n;
    }
    
    void output() {
    }
    
    void solution() {
        for (int i = 0; i < n; i++) {
            cin >> name;
            int res = db[name];
            
            if (!res) cout << "OK\n";
            else cout << name << res << endl;
            
            db[name]++;
        }
    }
    
public:
    
    Solution() {
    }
    
    void solve() {
        input();
        solution();
        output();
    }
};

int main() {
    Solution s = Solution();
    s.solve();
    return 0;
}