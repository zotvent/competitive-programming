class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        const int n = height.size();
        vector<int> leftMax = height, rightMax = height;
        
        for (int i = 1; i < n; i++) leftMax[i] = max(leftMax[i], leftMax[i - 1]);
        for (int i = n - 2; i >= 0; i--) rightMax[i] = max(rightMax[i], rightMax[i + 1]);
        
        for (int i = 1; i < n - 1; i++) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return res;
    }
};