class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = calc_xy(grid);
        int yz = calc_yz(grid);
        int zx = calc_zx(grid);
        return xy + yz + zx;
    }

    int calc_xy(vector<vector<int>>& grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j])
                    res++;
        
        return res;
    }

    int calc_yz(vector<vector<int>>& grid) {
        int res = 0;
        int size = grid.size();

        for (int j = 0; j < size; j++) {
            int mx = 0;
            for (int i = 0; i < size; i++)
                mx = max(mx, grid[i][j]);
            res += mx;
        }

        return res;
    }

    int calc_zx(vector<vector<int>>& grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            int mx = 0;
            for (int j = 0; j < grid[i].size(); j++)
                mx = max(mx, grid[i][j]);
            res += mx;
        }

        return res;
    }
};