class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, S, 0, 0);
    }
    
    int dfs(vector<int>& nums, int S, int cur, int index) {
        if (index == nums.size()) {
            return (cur == S ? 1 : 0);
        }
        
        int plus = dfs(nums, S, cur + nums[index], index + 1);
        int minus = dfs(nums, S, cur - nums[index], index + 1);
        
        return plus + minus;
    }
};