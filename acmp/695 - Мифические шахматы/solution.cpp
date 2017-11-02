#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

#define F first
#define S second
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 1e3;
const int N = 205;
const int mod = 1743;
const int MAX = 2500;
const int shift = 4;

using namespace std;

int d[10][10];
int elephantDx[] = {-1, -1, 1, 1};
int elephantDy[] = {-1, 1, -1, 1};
int knightDx[] = {2, 2, -2, -2, -1, 1, -1, 1};
int knightDy[] = {-1, 1, -1, 1, 2, 2, -2, -2};
pair<char, char> s, e;

void input() {
    speed
    cin >> s.F >> s.S >> e.F >> e.S;
}

int atX(pii coordinate) {
    return (int) (coordinate.F - 'A') + 1;
}

int atY(pii coordinate) {
    return (int) (coordinate.S - '1') + 1;
}

bool valid(int x, int y) {
    return x > 0 && y > 0 && x <= 9 && y <= 9;
}

void solve() {
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            d[i][j] = inf;
    d[atX(s)][atY(s)] = 0;
    queue<pii> q;
    q.push(mp(atX(s), atY(s)));
    while (!q.empty()) {
        int row = q.front().F;
        int column = q.front().S;
        q.pop();
        // black
        if ((row + column)%2 == 0) {
            for (int i = 0; i < 4; i++) {
                int x = row + elephantDx[i];
                int y = column + elephantDy[i];
                while (valid(x, y)) {
                    if (d[x][y] > d[row][column]+1) {
                        d[x][y] = d[row][column]+1;
                        q.push(mp(x, y));
                    }
                    x += elephantDx[i];
                    y += elephantDy[i];
                }
            }
        }
        // white
        else {
            for (int i = 0; i < 8; i++) {
                int x = row + knightDx[i];
                int y = column + knightDy[i];
                if (valid(x, y))
                    if (d[x][y] > d[row][column]+1) {
                        d[x][y] = d[row][column]+1;
                        q.push(mp(x, y));
                    }
            }
        }
    }
}

void output() {
    int res = d[atX(e)][atY(e)];
    cout << (res == inf ? -1 : res);
}

int main() {
    input();
    solve();
    output();
    return 0;
}