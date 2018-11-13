class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
            sum += nums[i];
        }
        return sum - mini * nums.size();
    }
};