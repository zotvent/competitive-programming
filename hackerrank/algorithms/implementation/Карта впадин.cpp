#include <bits/stdc++.h>

using namespace std;

int main(){
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    for (int i = 1; i < n-1; i++)
        for (int j = 1; j < n-1; j++) {
            if (grid[i][j] == 'X')
                continue;
            int max = 0;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if (grid[x][y] != 'X') {
                    max = ::max(max, grid[x][y]-'0');
                    cnt++;
                }
            }
            if (cnt == 4 && max < grid[i][j]-'0')
                grid[i][j] = 'X';
        }
    for (int i = 0; i < n; i++) 
        cout << grid[i] << endl;
    return 0;
}
