class Solution {
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, res, start + 1);
            swap(nums[start], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }
};