class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int res = 0;
        
        vector< vector<int> > a(n, vector<int>(m, 0));
        int ri, ci;
        for (int i = 0; i < indices.size(); i++) {
            ri = indices[i][0];
            ci = indices[i][1];
            
            for (int j = 0; j < n; j++) a[j][ci]++;
            for (int j = 0; j < m; j++) a[ri][j]++;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] & 1) {
                    res++;
                }
            }
        }
        
        return res;
    }
};