class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int n = triangle.size();
        vector<int> cur, prev = triangle[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            cur = triangle[i];
            for (int j = 0; j < cur.size(); j++) {
                cur[j] += min(prev[j], prev[j + 1]);
            }
            prev = cur;
        }
        
        return prev[0];
    }
};