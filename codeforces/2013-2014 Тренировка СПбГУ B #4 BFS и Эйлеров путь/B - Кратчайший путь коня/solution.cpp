#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define For(i, start, end) for (int (i) = (start); (i) < (end); (i)++)
#define rof(i, start, end) for (int (i) = (start); (i) > (end); (i)--)
#define mp(i, j) make_pair (i, j)

using namespace std;

int main() {
    freopen("knight1.in", "r", stdin);
    freopen("knight1.out", "w", stdout);

    int used[8][8] = {0};
    pair<int, int> begin, end, p[8][8];

    char a, b;
    cin >> a >> b;
    begin = mp(a-'a', b-'1');
    cin >> a >> b;
    end = mp(a-'a', b-'1');

    queue<pair<int, int>> q;
    q.push(begin);
    used[begin.first][begin.second] = 1;
    p[begin.first][begin.second] = mp(-1, -1);
    while (q.size() != 0) {
        int row = q.front().first, column = q.front().second;
        q.pop();
        for (int i = -2; i < 3; i += 4) {
            int x = row + i;
            if (x < 0 || x > 7) continue;
            for (int j = -1; j < 2; j += 2) {
                int y = column + j;
                if (y < 0 || y > 7) continue;
                if (!used[x][y]) {
                    q.push(mp(x, y));
                    used[x][y] = 1;
                    p[x][y] = mp(row, column);
                }
            }
        }
        for (int i = -2; i < 3; i += 4) {
            int y = column + i;
            if (y < 0 || y > 7) continue;
            for (int j = -1; j < 2; j += 2) {
                int x = row + j;
                if (x < 0 || x > 7) continue;
                if (!used[x][y]) {
                    q.push(mp(x, y));
                    used[x][y] = 1;
                    p[x][y] = mp(row, column);
                }
            }
        }
    }
    
    vector<pair<int, int>> path;
    for (pair<int, int> i = end; i != mp(-1, -1); i = p[i.first][i.second]) 
        path.push_back(i);
    rof(i, path.size()-1, -1) 
        cout << (char) (path[i].first + 'a') << (char) (path[i].second + '1') << "\n";

    return 0;
}