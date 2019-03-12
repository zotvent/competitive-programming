class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        
        res[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i];
        }
        
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] = right;
            if (i > 0) {
                res[i] *= res[i - 1];
            }
            right *= nums[i];
        }
        
        return res;
    }
};