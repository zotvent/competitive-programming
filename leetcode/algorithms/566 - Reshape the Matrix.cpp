class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int height = nums.size(), width = nums[0].size();
        
        if (height * width != r * c) return nums;
        else {
            vector<vector<int>> matrix(r, vector<int>(c));
            int row = 0, column = 0;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = 0; j < nums[i].size(); j++) {
                    matrix[row][column++] = nums[i][j];
                    if (column == c) {
                        row++;
                        column = 0;
                    }
                }
            }
            return matrix;
        }
    }
};