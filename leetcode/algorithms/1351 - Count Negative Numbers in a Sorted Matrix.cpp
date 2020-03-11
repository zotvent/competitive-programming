class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        bool found;
        
        for (int i = grid.size() - 1; i >= 0; i--) {
            found = false;
            
            for (int j = grid[i].size() - 1; j >= 0; j--) {
                if (grid[i][j] >= 0) break;
                res++;
                found = true;
            }
            
            if (!found) break;
        }
        
        return res;
    }
};