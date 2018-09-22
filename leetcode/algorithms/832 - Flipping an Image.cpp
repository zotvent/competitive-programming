class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res = A;
        int size = res.size();
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size / 2; j++)
                swap(res[i][j], res[i][size - j - 1]);
            
            for (int j = 0; j < size; j++)
                res[i][j] = !res[i][j];
        }
        
        
        return res;
    }
};