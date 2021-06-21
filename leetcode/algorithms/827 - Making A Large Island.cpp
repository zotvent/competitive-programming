class Solution {
    
    int get(int i, int j, vector<vector<int>>& g) {
      return (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) ? 0 : g[i][j];
    }
    
    int paint(int i, int j, int clr, vector<vector<int>>& g) {
      if (get(i, j, g) != 1) return 0;
      g[i][j] = clr;
      return 1 + paint(i + 1, j, clr, g) + paint(i - 1, j, clr, g) + paint(i, j + 1, clr, g) + paint(i, j - 1, clr, g);
    }

public:

    int largestIsland(vector<vector<int>>& g) {
        int res = 0, size;
        vector<int> sizes = {0, 0};
        unordered_set<int> seen;
        
        for (auto i = 0; i < g.size(); ++i) {
            for (auto j = 0; j < g[i].size(); ++j) {
                if (g[i][j] == 1) {
                    sizes.push_back(paint(i, j, sizes.size(), g));
                    res = max(res, sizes.back());
                }
            }
        }

        for (auto i = 0; i < g.size(); ++i) {
            for (auto j = 0; j < g[i].size(); ++j) {
                if (g[i][j] == 0) {
                    seen = { get(i + 1, j, g), get(i - 1, j, g), get(i, j + 1, g), get(i, j - 1, g) };
                    size = 1;
                    for (auto& i: seen) size += sizes[i];
                    res = max(res, size);
                    seen.clear();
                }
            }
        }

        return res;
    }
};