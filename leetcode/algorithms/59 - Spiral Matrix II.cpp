class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        int cnt = 1;
        int left = 0, right = n - 1;
        int top = 0, down = n - 1;
        
        while (cnt <= n * n) {
            for (int i = left; i <= right; i++) res[top][i] = cnt++;
            top++;
            
            for (int i = top; i <= down; i++) res[i][right] = cnt++;
            right--;
            
            for (int i = right; i >= left; i--) res[down][i] = cnt++;
            down--;
            
            for (int i = down; i >= top; i--) res[i][left] = cnt++;
            left++;
        }
        
        return res;
    }
};