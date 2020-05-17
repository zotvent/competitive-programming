class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }

        vector<vector<int>> res = image;
        
        int n = image.size();
        int m = (image.empty() ? 0 : image[0].size());
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        
        int oldColor = image[sr][sc];
        queue<pair<int, int>> q;
        vector<vector<int>> used(n, vector<int>(m, 0));
        
        q.push(make_pair(sr, sc));
        used[sr][sc] = 1;
        res[sr][sc] = newColor;
        
        int x, y;
        pair<int, int> v;
        
        while (!q.empty()) {
            v = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                x = v.first + dx[i];
                y = v.second + dy[i];
                
                if (valid(x, y, n, m) && !used[x][y] && image[x][y] == oldColor) {
                    used[x][y] = 1;
                    res[x][y] = newColor;
                    q.push(make_pair(x, y));
                }
            }
        }
        
        return res;
    }
    
    bool valid(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
};