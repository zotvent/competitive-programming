class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> brickAllocations;
        int climb;
        
        for (int i = 0; i < heights.size() - 1; i++) {
            climb = heights[i + 1] - heights[i];
            
            if (climb < 1) continue;
            
            brickAllocations.push(climb);
            bricks -= climb;
            
            if (bricks < 0 && ladders == 0) {
                return i;
            }
            
            if (bricks < 0) {
                bricks += brickAllocations.top();
                brickAllocations.pop();
                ladders--;
            }
        }
        
        return heights.size() - 1;
    }
};