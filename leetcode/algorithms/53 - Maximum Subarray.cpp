class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        
        int sum = res;
        for (int i = 1; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            res = max(res, sum);
        }
        
        return res;
    }
};