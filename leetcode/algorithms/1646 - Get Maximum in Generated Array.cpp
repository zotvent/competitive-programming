class Solution {
public:
    int getMaximumGenerated(int n) {
        int res = INT_MIN;
        vector<int> nums(n + 1, 0);
        
        for (int i = 0; i <= n; i++) {
            if (i == 0) nums[i] = 0;
            else if (i == 1) nums[i] = 1;
            else {
                nums[i] = nums[i / 2] + (i % 2 == 0 ? 0 : nums[i / 2 + 1]);
            }
            res = max(res, nums[i]);
        }
        
        return res;
    }
};