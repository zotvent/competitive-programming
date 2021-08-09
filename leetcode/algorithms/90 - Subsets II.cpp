class Solution {
    
    void backtrack(vector<int>& nums, int head, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);
        
        for (int i = head; i < nums.size(); i++) {
            if (i != head && nums[i] == nums[i - 1]) {
                continue;
            }
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, cur, res);
        return res;
    }
};