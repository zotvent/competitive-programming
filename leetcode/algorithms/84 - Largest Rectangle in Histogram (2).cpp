class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> mins;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            while (!mins.empty() && heights[mins.back()] >= heights[i]) {
                int index = mins.back();
                mins.pop_back();
                int leftBorder = mins.empty() ? -1 : mins.back();
                res = max(res, heights[index] * (i - leftBorder - 1));
            }
            mins.push_back(i);
        }
        
        return res;    
    }
};