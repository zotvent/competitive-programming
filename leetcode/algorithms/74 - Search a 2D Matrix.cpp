class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix.empty() ? 0 : matrix[0].size();
        
        int left = 0, right = n * m - 1;
        int index, element;
        
        while (left <= right) {
            index = left + (right - left) / 2;
            element = matrix[index / m][index % m];
            
            if (element == target) {
                return true;
            }
            else if (element < target) {
                left = index + 1;
            }
            else {
                right = index - 1;
            }
        }
        
        return false;
    }
};