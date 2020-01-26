class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> res = mat;
        
        for(int k = 0; k + 1 < res.size(); k++)
             for(int i = 0; i + 1 < res.size(); i++)
                for(int j = 0; j + 1 < res[i].size(); j++)
                    if(res[i][j] > res[i + 1][j + 1])
                        swap(res[i][j], res[i + 1][j + 1]);   

        return res;
    }
};