#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define For(i, start, end) for (int (i) = (start); (i) < (end); (i)++)
#define rof(i, start, end) for (int (i) = (start); (i) > (end); (i)--)
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair

const int INF = 2000000000, NMAX = 4096 + 5;

using namespace std;

struct State {
    int c[2][2];

    void print() {
        cout << c[0][0] << c[0][1] << " " << c[1][0] << c[1][1] << "\n";
    }
};

int stateToInt(State s) {
    return s.c[0][0]*512 + s.c[0][1]*64 + s.c[1][0]*8 + s.c[1][1];
}

State intToState(int n) {
    State s;
    s.c[1][1] = n%8;
    n /= 8;
    s.c[1][0] = n%8;
    n /= 8;
    s.c[0][1] = n%8;
    s.c[0][0] = n/8;
    return s;
}

State input() {
    char a, b, c, d;
    cin >> a >> b >> c >> d;
    State s;
    s.c[0][0] = (int) (a-'a');
    s.c[0][1] = (int) (b-'1');
    s.c[1][0] = (int) (c-'a');
    s.c[1][1] = (int) (d-'1');
    return s;
}

bool isValid(int n) {
    return n >= 0 && n < 8;
}

bool isValid(State s) {
    For(i, 0, 2)
        For(j, 0, 2)
            if (!isValid(s.c[i][j]))
                return false;
    return true;
}

bool inTheSameCell(State s) {
    return s.c[0][0] == s.c[1][0] && s.c[0][1] == s.c[1][1];
}

int main() {
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);

    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    vector<int> d(NMAX, INF), p(NMAX, -1);

    State begin, end;
    begin = input();
    end = input();

    queue<State> q;
    q.push(begin);
    d[stateToInt(begin)] = 0;
    while (!q.empty()) {
        State cur = q.front();
        int cur_i = stateToInt(cur);
        q.pop();
        For(i, 0, 2)
            For(j, 0, 8) {
                int nx = cur.c[i][0] + dx[j];
                int ny = cur.c[i][1] + dy[j];
                State nst = cur;
                nst.c[i][0] = nx;
                nst.c[i][1] = ny;
                int nst_i = stateToInt(nst);
                if (isValid(nst) && d[nst_i] > d[cur_i]+1 && !inTheSameCell(nst)) {
                    d[nst_i] = d[cur_i]+1;
                    p[nst_i] = cur_i;
                    q.push(nst);
                }
            }
    }

    vector<State> path;
    path.push_back(end);
    for (int i = p[stateToInt(end)]; i != -1; i = p[i])
        path.push_back(intToState(i));

    reverse(path.begin(), path.end());
    For(i, 1, path.size()) {
        if (i-1) cout << "\n";
        if (path[i-1].c[0][0] == path[i].c[0][0] && path[i-1].c[0][1] == path[i].c[0][1])
            cout << 2 << " " << (char) (path[i].c[1][0]+'a') << (char) (path[i].c[1][1]+'1');
        else
            cout << 1 << " " << (char) (path[i].c[0][0]+'a') << (char) (path[i].c[0][1]+'1');
    }

    return 0;
}