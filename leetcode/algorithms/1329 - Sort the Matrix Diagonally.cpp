class Solution {
    
    void calc(vector<vector<int>>& res, vector<vector<int>>& mat, int row, int col) {
        vector<int> cur;
        const int rows = mat.size();
        const int cols = (mat.empty() ? 0 : mat[0].size());
        int r = row, c = col;
        
        while (r < rows && c < cols) {
            cur.push_back(mat[r++][c++]);
        }
        
        sort(cur.begin(), cur.end());

        r = row;
        c = col;
        int index = 0;

        while (r < rows && c < cols) {
            res[r++][c++] = cur[index++];
        }

        cur.clear();
    }
    
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> res = mat;
        const int rows = mat.size();
        const int cols = (mat.empty() ? 0 : mat[0].size());
        
        for (int col = 0; col < cols; col++) calc(res, mat, 0, col);
        for (int row = 1; row < rows; row++) calc(res, mat, row, 0);
        
        return res;
    }
};