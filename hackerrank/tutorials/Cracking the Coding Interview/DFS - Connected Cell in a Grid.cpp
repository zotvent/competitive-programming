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

#define pii pair<int, int>
#define mp make_pair
#define F first 
#define S second 

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs(int sx, int sy, vector<vector<int>> &used, vector<vector<int>> &grid) {
    int dx[] = {0, 0, 1, 1, 1, 1, -1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
    int cnt = 1, i;
    queue<pii> q;
    
    q.push(mp(sx, sy));
    used[sx][sy] = 1;
    
    while (!q.empty()) {
        pii v = q.front();
        q.pop();
        for (i = 0; i < 8; i++) {
            int x = v.F + dx[i];
            int y = v.S + dy[i];
            if (valid(x, y, grid.size(), grid[0].size()))
                if (!used[x][y] && grid[x][y]) {
                    used[x][y] = 1;
                    q.push(mp(x, y));
                    cnt++;
                }
        }
    }
    
    return cnt;
}

int dfs(int sx, int sy, vector<vector<int>> &used, vector<vector<int>> &grid) {
    used[sx][sy] = 1;
    
    int dx[] = {0, 0, 1, 1, 1, 1, -1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
    int cnt = 1;
    
    for (int i = 0; i < 8; i++) {
        int x = sx + dx[i];
        int y = sy + dy[i];
        if (valid(x, y, grid.size(), grid[0].size()))
            if (!used[x][y] && grid[x][y]) {
                used[x][y] = 1;
                cnt += dfs(x, y, used, grid);
            }
    }

    return cnt;
}

int get_biggest_region(vector< vector<int> > grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> used(n, vector<int>(m, 0));
    int i, j;
    int res = 0;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (grid[i][j] && !used[i][j])
                //res = max(res, bfs(i, j, used, grid));
                res = max(res, dfs(i, j, used, grid));
    
    return res;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
