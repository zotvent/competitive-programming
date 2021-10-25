class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int top = x, bottom = x;
        int left = y, right = y;
        
        for (int row = 0; row < image.size(); row++) {
            for (int col = 0; col < image[row].size(); col++) {
                if (image[row][col] == '1') {
                    top = min(top, row);
                    bottom = max(bottom, row);
                    left = min(left, col);
                    right = max(right, col);
                }
            }
        }
        
        return (bottom - top + 1) * (right - left + 1);
    }
};