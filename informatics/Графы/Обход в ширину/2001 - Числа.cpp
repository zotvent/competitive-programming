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
const int N = 1e4 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {
    vector<int> used, p;
    int s, e, temp;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> s >> e;
        prepare();
    }
    
    void prepare() {
        used.assign(N, 0);
        p.assign(N, -1);
    }
    
    void output() {
        vector<int> path;
        path.pb(e);
        for (int i = p[e]; i != -1; i = p[i])
            path.pb(i);

        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << endl;
    }
    
    void solution() {
        bfs();
    }
    
    void bfs() {
        queue<int> q;
        q.push(s);
        used[s] = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            // first
            if (v / 1000 != 9) {
                temp = v + 1000;
                if (!used[temp]) {
                    q.push(temp);
                    used[temp] = 1;
                    p[temp] = v;
                }
            }

            // second
            if (v % 10 != 1) {
                temp = v - 1;
                if (!used[temp]) {
                    q.push(temp);
                    used[temp] = 1;
                    p[temp] = v;
                }
            }

            // third
            temp = (v % 10) * 1000 + v / 10;
            if (!used[temp]) {
                q.push(temp);
                used[temp] = 1;
                p[temp] = v;
            }

            // fourth
            temp = (v % 1000) * 10 + v / 1000;
            if (!used[temp]) {
                q.push(temp);
                used[temp] = 1;
                p[temp] = v;
            }
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
