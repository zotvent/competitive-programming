class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto complement = m.find(target - nums[i]);
            
            if (complement != m.end()) {
                res.push_back(complement->second);
                res.push_back(i);
            }
            
            m[nums[i]] = i;
        }
        
        return res;
    }
};