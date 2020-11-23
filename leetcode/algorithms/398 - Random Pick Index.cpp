class Solution {
    
    unordered_map<int, vector<int>> indices;
    
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size = indices[target].size();
        int index = indices[target][rand() % size];
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */