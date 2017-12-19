class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor)
            return image;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        int color = image[sr][sc];
        image[sr][sc] = newColor;

        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        
        while (!q.empty()) {
            pair<int, int> v = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = v.first + dx[i];
                int y = v.second + dy[i];
                if (valid(x, y, image.size(), image[0].size())) {
                    if (image[x][y] == color) {
                        image[x][y] = newColor;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
        
        return image;
    }
    
    bool valid(int x, int y, int rows, int columns) {
        return x >= 0 && y >= 0 && x < rows && y < columns;
    }
};