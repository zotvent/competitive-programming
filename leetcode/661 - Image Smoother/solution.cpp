class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> v = M;
        for (int i = 0; i < M.size(); i++)
            for (int j = 0; j < M[i].size(); j++)
                v[i][j] = average(M, i, j);
        return v;
    }
    
    int average(vector<vector<int>>& M, int row, int column) {
        int cnt = 0, sum = 0;
        for (int i = row-1; i <= row+1; i++)
            for (int j = column-1; j <= column+1; j++)
                if (valid(M, i, j)) {
                    cnt++;
                    sum += M[i][j];
                }
        return sum/cnt;
    }
    
    bool valid(vector<vector<int>>& M, int row, int column) {
        return row >= 0 && row < M.size() && column >= 0 && column < M[0].size();
    }
};