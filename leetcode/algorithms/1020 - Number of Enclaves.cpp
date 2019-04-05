class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int res = 0;
        
        int max_x = A.size();
        int max_y = A[0].size();
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (isEdge(i, j, max_x, max_y) && A[i][j]) {
                    bfs(A, i, j);
                }
            }
        }
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                res += A[i][j];
            }
        }
        
        return res;
    }
    
    void bfs(vector<vector<int>>& A, int row, int col) {
        queue<pair<int, int>> to_visit;
        
        to_visit.push({row, col});
        A[row][col] = 0;
        
        int max_x = A.size();
        int max_y = A[0].size();
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        while (!to_visit.empty()) {
            pair<int, int> coor = to_visit.front();
            to_visit.pop();
            
            int x = coor.first;
            int y = coor.second;
            
            for (int i = 0; i < 4; i++) {
                int to_x = x + dx[i];
                int to_y = y + dy[i];
                
                if (valid(to_x, to_y, max_x, max_y) && A[to_x][to_y]) {
                    A[to_x][to_y] = 0;
                    to_visit.push({to_x, to_y});
                }
            }
        }
    }
    
    bool valid(int x, int y, int max_x, int max_y) {
        return x >= 0 && y >= 0 && x < max_x && y < max_y;
    }
    
    bool isEdge(int x, int y, int max_x, int max_y) {
        return x == 0 || y == 0 || x == max_x - 1 || y == max_y - 1;
    }
};