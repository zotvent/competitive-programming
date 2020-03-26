class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i]) > 0) {
                res = {m[target - nums[i]], i};
                break;
            }
            m[nums[i]] = i;
        }
        
        return res;
    }
};