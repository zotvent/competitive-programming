class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum = 0;
        for (auto x: nums) {
            sum += x;
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
    }
};