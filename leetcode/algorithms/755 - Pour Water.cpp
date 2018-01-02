class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        while (V > 0) {
            V--;
            int cur = heights[K];
     
            //left
            int index = K;
            for (int i = K-1; i >= 0; i--) {
                if (heights[i] > heights[i+1]) break;
                if (heights[i] < cur) {
                    cur = heights[i];
                    index = i;
                }
            }
            if (index != K && heights[index] < heights[K]) {
                heights[index]++;
                continue;
            }
            
            //right
            for (int i = K+1; i < heights.size(); i++) {
                if (heights[i] > heights[i-1]) break;
                if (heights[i] < cur) {
                    cur = heights[i];
                    index = i;
                }
            }
            if (index != K && heights[index] < heights[K]) {
                heights[index]++;
                continue;
            }
            
            //stay one the same cell
            heights[K]++;
        }
        return heights;
    }
};