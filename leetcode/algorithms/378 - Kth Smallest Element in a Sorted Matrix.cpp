class Solution {
    
    int count(vector<vector<int>>& matrix, vector<int>& extremes, int mid) {
        const int n = matrix.size();
        int cnt = 0, row = n - 1, col = 0;
        
        while (row >= 0 && col < n) {
            if (matrix[row][col] > mid) {
                extremes[1] = min(extremes[1], matrix[row--][col]);
            }
            else {
                cnt += row + 1;
                extremes[0] = max(extremes[0], matrix[row][col++]);
            }
        }
        
        return cnt;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();
        int start = matrix[0][0], end = matrix[n - 1][n - 1], mid, cnt;
        vector<int> extremes;
        
        while (start < end) {
            mid = start + (end - start) / 2;
            extremes = {matrix[0][0], matrix[n - 1][n - 1]};
            cnt = count(matrix, extremes, mid);
            
            if (cnt == k) return extremes[0];
            else if (cnt < k) start = extremes[1];
            else end = extremes[0];
        }
        
        return start;
    }
};