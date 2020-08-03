class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {        
        int res = 0;
        
        int n = heights.size();
        int prev;
        
        vector<int> lessFromLeft(n, -1);
        vector<int> lessFromRight(n, n);
        
        for (int i = 1; i < n; i++) {
            prev = i - 1;
            
            while (prev >= 0 && heights[prev] >= heights[i]) {
                prev = lessFromLeft[prev];
            }
            
            lessFromLeft[i] = prev;
        }
        
        for (int i = n - 2; i >= 0; i--) {
            prev = i + 1;
            
            while (prev < n && heights[prev] >= heights[i]) {
                prev = lessFromRight[prev];
            }
            
            lessFromRight[i] = prev;
        }
        
        for (int i = 0; i < n; i++) {
            res = max(res, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
        }
        
        return res;
    }
};