class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        
        vector<int> cur;
        backtrack(nums, cur, res, 0);
        
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& cur, vector<vector<int>>& res, int head) {
        if (head >= nums.size()) {
            res.push_back(cur);
            return;
        }
        
        backtrack(nums, cur, res, head + 1);
        
        cur.push_back(nums[head]);
        backtrack(nums, cur, res, head + 1);
        cur.pop_back();
    }
};